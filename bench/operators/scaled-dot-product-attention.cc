// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <random>
#include <vector>

#include "bench/utils.h"
#include "include/xnnpack.h"
#include "src/xnnpack/buffer.h"
#include <benchmark/benchmark.h>

void xnnpack_multihead_scaled_batch_matrix_multiply_cap_tanh_f32(
    benchmark::State& state, const char* net) {
  const size_t batch_size = state.range(0);
  const size_t heads = state.range(1);
  const size_t query_tokens = state.range(2);
  const size_t key_value_tokens = state.range(3);
  const size_t channels = state.range(4);
  const float cap_value = 30.0f;

  std::random_device random_device;
  auto rng = std::mt19937(random_device());
  std::uniform_real_distribution<float> f32dist(-1.0f, 1.0f);
  std::uniform_real_distribution<float> scaledist(0.2f, 2.0f);

  xnnpack::Buffer<float> query(batch_size * heads * query_tokens * channels,
                               xnnpack::XnnExtraBytes);
  xnnpack::Buffer<float> key(batch_size * heads * key_value_tokens * channels,
                             xnnpack::XnnExtraBytes);
  xnnpack::Buffer<float> value(batch_size * heads * key_value_tokens * channels,
                               xnnpack::XnnExtraBytes);
  xnnpack::Buffer<float> scale(channels, xnnpack::XnnExtraBytes);
  xnnpack::Buffer<float> mask(query_tokens * key_value_tokens,
                              xnnpack::XnnExtraBytes);
  xnnpack::Buffer<float> output(batch_size * heads * query_tokens * channels);

  xnnpack::Buffer<float> query_scaled(
      batch_size * heads * query_tokens * channels, xnnpack::XnnExtraBytes);
  xnnpack::Buffer<float> logits(
      batch_size * heads * query_tokens * key_value_tokens,
      xnnpack::XnnExtraBytes);

  std::generate(query.begin(), query.end(), [&]() { return f32dist(rng); });
  // Use a different distribution to avoid divide by 0.
  std::generate(scale.begin(), scale.end(), [&]() { return scaledist(rng); });
  std::generate(key.begin(), key.end(), [&]() { return f32dist(rng); });
  std::generate(value.begin(), value.end(), [&]() { return f32dist(rng); });
  std::generate(mask.begin(), mask.end(), [&]() { return f32dist(rng); });

  xnn_status status = xnn_initialize(/*allocator=*/nullptr);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to initialize XNNPACK");
  }

  xnn_operator_t q_scale_mul_op = nullptr;
  status = xnn_create_binary_elementwise_nd(
      xnn_binary_multiply, xnn_datatype_fp32, nullptr, nullptr, nullptr,
      /*flags=*/0, &q_scale_mul_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to create Multiply operator");
  }

  xnn_operator_t qk_bmm_op = nullptr;
  status = xnn_create_batch_matrix_multiply_nc_f32(
      /*flags=*/XNN_FLAG_TRANSPOSE_B, &qk_bmm_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to create Batch Matrix Multiply operator");
  }

  xnn_operator_t divide_op = nullptr;
  status = xnn_create_binary_elementwise_nd(xnn_binary_divide,
                                            xnn_datatype_fp32, nullptr, nullptr,
                                            nullptr, /*flags=*/0, &divide_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to create Divide operator");
  }

  xnn_operator_t tanh_op = nullptr;
  status = xnn_create_unary_elementwise_nc(xnn_unary_tanh, xnn_datatype_fp32,
                                           xnn_datatype_fp32, nullptr, nullptr,
                                           nullptr, /*flags=*/0, &tanh_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to create TanH operator");
  }

  xnn_operator_t mul_cap_op = nullptr;
  status = xnn_create_binary_elementwise_nd(xnn_binary_multiply,
                                            xnn_datatype_fp32, nullptr, nullptr,
                                            nullptr, /*flags=*/0, &mul_cap_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to create Divide operator");
  }

  xnn_operator_t add_op = nullptr;
  status = xnn_create_binary_elementwise_nd(xnn_binary_add, xnn_datatype_fp32,
                                            nullptr, nullptr, nullptr,
                                            /*flags=*/0, &add_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to create Add operator");
  }

  xnn_operator_t softmax_op = nullptr;
  status = xnn_create_softmax_nc_f32(/*flags=*/0, &softmax_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to create Softmax operator");
  }

  xnn_operator_t attn_value_bmm_op = nullptr;
  status =
      xnn_create_batch_matrix_multiply_nc_f32(/*flags=*/0, &attn_value_bmm_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to create Batch Matrix Multiply operator");
  }

  std::array<size_t, 4> query_dims = {batch_size, heads, query_tokens,
                                      channels};
  std::array<size_t, 1> scale_dims = {channels};
  status = xnn_reshape_binary_elementwise_nd(
      q_scale_mul_op, query_dims.size(), query_dims.data(), scale_dims.size(),
      scale_dims.data(), /*threadpool=*/nullptr);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to reshape Multiply operator");
  }

  size_t workspace_size = 0;
  size_t workspace_alignment = 0;
  const size_t batch_dims = batch_size * heads;
  status = xnn_reshape_batch_matrix_multiply_nc_f32(
      qk_bmm_op, /*num_batch_dims=*/1, /*batch_dims_a=*/&batch_dims,
      /*batch_dims_b=*/&batch_dims, query_tokens, channels, key_value_tokens,
      &workspace_size, &workspace_alignment, /*threadpool=*/nullptr);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to reshape Batch Matrix Multiply operator");
  }

  std::array<size_t, 4> logits_dims = {batch_size, heads, query_tokens,
                                       key_value_tokens};
  std::array<size_t, 1> cap_tanh_dims = {1};

  status = xnn_reshape_binary_elementwise_nd(
      divide_op, logits_dims.size(), logits_dims.data(), cap_tanh_dims.size(),
      cap_tanh_dims.data(), /*threadpool=*/nullptr);

  status = xnn_reshape_unary_elementwise_nc(
      tanh_op, batch_size * heads * query_tokens, key_value_tokens,
      key_value_tokens, key_value_tokens, /*threadpool=*/nullptr);

  status = xnn_reshape_binary_elementwise_nd(
      mul_cap_op, logits_dims.size(), logits_dims.data(), cap_tanh_dims.size(),
      cap_tanh_dims.data(), /*threadpool=*/nullptr);

  std::array<size_t, 2> mask_dims = {query_tokens, key_value_tokens};

  status = xnn_reshape_binary_elementwise_nd(
      add_op, logits_dims.size(), logits_dims.data(), mask_dims.size(),
      mask_dims.data(), /*threadpool=*/nullptr);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to reshape Add operator");
  }

  status = xnn_reshape_softmax_nc_f32(
      softmax_op, key_value_tokens, key_value_tokens, key_value_tokens,
      batch_size * heads * query_tokens, /*threadpool=*/nullptr);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to reshape Softmax operator");
  }

  size_t workspace_size2 = 0;
  size_t workspace_alignment2 = 0;
  status = xnn_reshape_batch_matrix_multiply_nc_f32(
      attn_value_bmm_op, /*num_batch_dims=*/1, /*batch_dims_a=*/&batch_dims,
      /*batch_dims_b=*/&batch_dims, query_tokens, key_value_tokens, channels,
      &workspace_size2, &workspace_alignment2, /*threadpool=*/nullptr);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to reshape Batch Matrix Multiply operator");
  }

  xnnpack::Buffer<char> workspace2(workspace_size2, 0);

  status = xnn_setup_binary_elementwise_nd(q_scale_mul_op, query.data(),
                                           scale.data(), query_scaled.data());
  if (status != xnn_status_success) {
    state.SkipWithError("failed to setup Multiply operator");
  }

  xnnpack::Buffer<char> workspace(workspace_size, 0);
  status = xnn_setup_batch_matrix_multiply_nc_f32(qk_bmm_op, workspace.data(),
                                                  query_scaled.data(),
                                                  key.data(), logits.data());
  if (status != xnn_status_success) {
    state.SkipWithError("failed to setup Batch Matrix Multiply operator");
  }

  status = xnn_setup_binary_elementwise_nd(divide_op, logits.data(), &cap_value,
                                           logits.data());
  if (status != xnn_status_success) {
    state.SkipWithError("failed to setup Divide operator");
  }

  status =
      xnn_setup_unary_elementwise_nc(tanh_op, logits.data(), logits.data());
  if (status != xnn_status_success) {
    state.SkipWithError("failed to setup Tanh operator");
  }

  status = xnn_setup_binary_elementwise_nd(mul_cap_op, logits.data(),
                                           &cap_value, logits.data());
  if (status != xnn_status_success) {
    state.SkipWithError("failed to setup Multiply operator");
  }

  status = xnn_setup_binary_elementwise_nd(add_op, logits.data(), mask.data(),
                                           logits.data());
  if (status != xnn_status_success) {
    state.SkipWithError("failed to setup Add operator");
  }

  status = xnn_setup_softmax_nc_f32(softmax_op, logits.data(), logits.data());
  if (status != xnn_status_success) {
    state.SkipWithError("failed to setup Softmax operator");
  }

  status = xnn_setup_batch_matrix_multiply_nc_f32(
      attn_value_bmm_op, workspace2.data(), logits.data(), value.data(),
      output.data());
  if (status != xnn_status_success) {
    state.SkipWithError("failed to setup Batch Matrix Multiply operator");
  }

  for (auto _ : state) {
    status = xnn_run_operator(q_scale_mul_op, /*threadpool=*/nullptr);
    if (status != xnn_status_success) {
      state.SkipWithError("failed to run Multiply operator");
    }
    status = xnn_run_operator(qk_bmm_op, /*threadpool=*/nullptr);
    if (status != xnn_status_success) {
      state.SkipWithError("failed to run Batch Matrix Multiply operator");
    }
    status = xnn_run_operator(divide_op, /*threadpool=*/nullptr);
    if (status != xnn_status_success) {
      state.SkipWithError("failed to run Addition operator");
    }
    status = xnn_run_operator(tanh_op, /*threadpool=*/nullptr);
    if (status != xnn_status_success) {
      state.SkipWithError("failed to run Addition operator");
    }
    status = xnn_run_operator(mul_cap_op, /*threadpool=*/nullptr);
    if (status != xnn_status_success) {
      state.SkipWithError("failed to run Addition operator");
    }
    status = xnn_run_operator(add_op, /*threadpool=*/nullptr);
    if (status != xnn_status_success) {
      state.SkipWithError("failed to run Addition operator");
    }
    status = xnn_run_operator(softmax_op, /*threadpool=*/nullptr);
    if (status != xnn_status_success) {
      state.SkipWithError("failed to run Softmax operator");
    }
    status = xnn_run_operator(attn_value_bmm_op, /*threadpool=*/nullptr);
    if (status != xnn_status_success) {
      state.SkipWithError("failed to run Batch Matrix Multiply operator");
    }
  }

  status = xnn_delete_operator(q_scale_mul_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to delete Multiply operator");
  }
  status = xnn_delete_operator(qk_bmm_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to delete Batch Matrix Multiply operator");
  }
  status = xnn_delete_operator(divide_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to delete Divide operator");
  }
  status = xnn_delete_operator(tanh_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to delete TanH operator");
  }
  status = xnn_delete_operator(mul_cap_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to delete Multiply operator");
  }
  status = xnn_delete_operator(add_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to delete Addition operator");
  }
  status = xnn_delete_operator(softmax_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to delete Softmax operator");
  }
  status = xnn_delete_operator(attn_value_bmm_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to delete Batch Matrix Multiply operator");
  }

  const uint64_t cpu_frequency = benchmark::utils::GetCurrentCpuFrequency();
  if (cpu_frequency != 0) {
    state.counters["cpufreq"] = cpu_frequency;
  }

  // See comment in xnnpack_multihead_scaled_dot_product_attention_cap_tanh_f32
  // for derivation of this.
  state.counters["FLOPS"] = benchmark::Counter(
      uint64_t(state.iterations()) * batch_size * heads * query_tokens *
          (channels + key_value_tokens * (channels * 2 + 5)),
      benchmark::Counter::kIsRate);
}

void xnnpack_multihead_scaled_dot_product_attention_cap_tanh_f32(
    benchmark::State& state, const char* net) {
  const size_t batch_size = state.range(0);
  const size_t heads = state.range(1);
  const size_t query_tokens = state.range(2);
  const size_t key_value_tokens = state.range(3);
  const size_t channels = state.range(4);
  const xnn_attention_logits_cap_type cap_type =
      xnn_attention_logits_cap_type_tanh;
  const float cap_value = 30.0f;

  std::random_device random_device;
  auto rng = std::mt19937(random_device());
  std::uniform_real_distribution<float> f32dist(-1.0f, 1.0f);
  std::uniform_real_distribution<float> scaledist(0.2f, 2.0f);

  xnnpack::Buffer<float> query(batch_size * heads * query_tokens * channels,
                               xnnpack::XnnExtraBytes);
  xnnpack::Buffer<float> key(batch_size * heads * key_value_tokens * channels,
                             xnnpack::XnnExtraBytes);
  xnnpack::Buffer<float> value(batch_size * heads * key_value_tokens * channels,
                               xnnpack::XnnExtraBytes);
  xnnpack::Buffer<float> scale(channels, xnnpack::XnnExtraBytes);
  xnnpack::Buffer<float> mask(query_tokens * key_value_tokens,
                              xnnpack::XnnExtraBytes);
  xnnpack::Buffer<float> output(batch_size * heads * query_tokens * channels);

  std::generate(query.begin(), query.end(), [&]() { return f32dist(rng); });
  // Use a different distribution to avoid divide by 0.
  std::generate(scale.begin(), scale.end(), [&]() { return scaledist(rng); });
  std::generate(key.begin(), key.end(), [&]() { return f32dist(rng); });
  std::generate(value.begin(), value.end(), [&]() { return f32dist(rng); });
  std::generate(mask.begin(), mask.end(), [&]() { return f32dist(rng); });

  // Create, setup, run, and destroy Scaled Dot Attention operator.
  xnn_status status = xnn_initialize(/*allocator=*/nullptr);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to initialize XNNPACK");
  }

  xnn_operator_t attention_op = nullptr;
  xnn_attention_logits_cap_tanh_params cap_tanh_params = {cap_value};
  status = xnn_create_scaled_dot_product_attention_nhtc_f32(
      cap_type, &cap_tanh_params,
      /*flags=*/0, &attention_op);

  if (status != xnn_status_success) {
    state.SkipWithError("failed to create Scaled Dot Attention operator");
  }

  size_t workspace_size = 0;
  size_t workspace_alignment = 0;
  status = xnn_reshape_scaled_dot_product_attention_nhtc_f32(
      attention_op, batch_size, heads, query_tokens, heads, key_value_tokens,
      channels, channels, &workspace_size, &workspace_alignment,
      /*threadpool=*/nullptr);

  if (status != xnn_status_success) {
    state.SkipWithError("failed to reshape Scaled Dot Attention operator");
  }

  xnnpack::Buffer<char> workspace(workspace_size, 0);

  status = xnn_setup_scaled_dot_product_attention_nhtc_f32(
      attention_op, workspace.data(), query.data(), key.data(), value.data(),
      scale.data(), mask.data(), output.data());

  if (status != xnn_status_success) {
    state.SkipWithError("failed to setup Scaled Dot Attention operator");
  }

  for (auto _ : state) {
    status = xnn_run_operator(attention_op, /*threadpool=*/nullptr);
    if (status != xnn_status_success) {
      state.SkipWithError("failed to run Scaled Dot Attention operator");
    }
  }

  status = xnn_delete_operator(attention_op);
  if (status != xnn_status_success) {
    state.SkipWithError("failed to setup Scaled Dot Attention operator");
  }

  const uint64_t cpu_frequency = benchmark::utils::GetCurrentCpuFrequency();
  if (cpu_frequency != 0) {
    state.counters["cpufreq"] = cpu_frequency;
  }

  // Q * Scale  : batch_size * heads * query_tokens * channels
  // Q * K      : batch_size * heads * query_tokens * key_value_tokens *
  // channels CapTanH    : batch_size * heads * query_tokens * key_value_tokens
  // * 3 Mask       : batch_size * heads * query_tokens * key_value_tokens
  // Softmax    : batch_size * heads * query_tokens * key_value_tokens (roughly)
  // Logits * V : batch_size * heads * query_tokens * key_value_tokens *
  // channels Total      : batch_size * heads * query_tokens * (channels +
  // key_value_tokens * (channels * 2 + 5))

  state.counters["FLOPS"] = benchmark::Counter(
      uint64_t(state.iterations()) * batch_size * heads * query_tokens *
          (channels + key_value_tokens * (channels * 2 + 5)),
      benchmark::Counter::kIsRate);
}

static void Bert(benchmark::internal::Benchmark* b) {
  b->ArgNames(
      {"BatchSize", "Heads", "QueryTokens", "KeyValueTokens", "Channels"});
  // Smaller BERT, number of heads = h/64
  // "Well-Read Students Learn Better: On the Importance of Pre-training Compact
  // Models." https://arxiv.org/abs/1908.08962
  b->Args({1, 2, 128, 128, 64});
  b->Args({1, 4, 128, 128, 64});
  b->Args({1, 8, 128, 128, 64});

  // Original BERT.
  b->Args({1, 12, 128, 128, 64});
  b->Args({1, 16, 128, 128, 64});
}

BENCHMARK_CAPTURE(xnnpack_multihead_scaled_dot_product_attention_cap_tanh_f32,
                  bert, "BERT")
    ->Apply(Bert)
    ->UseRealTime();
BENCHMARK_CAPTURE(xnnpack_multihead_scaled_batch_matrix_multiply_cap_tanh_f32,
                  bert, "BERT")
    ->Apply(Bert)
    ->UseRealTime();

#ifndef XNNPACK_BENCHMARK_NO_MAIN
XNN_BENCHMARK_MAIN();
#endif
