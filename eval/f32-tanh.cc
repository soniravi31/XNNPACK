// Copyright 2022 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <vector>

#include <gtest/gtest.h>

#include <fp16.h>

#include <xnnpack/aligned-allocator.h>
#include <xnnpack/common.h>
#include <xnnpack/isa-checks.h>
#include <xnnpack/math.h>
#include <xnnpack/math-stubs.h>


constexpr int kBlockSize = 1024;


#if XNN_ARCH_ARM64
  TEST(TANH__AARCH64_NEONFMA_RR1_P6_DIV, positive_saturation) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x41102CB4); n <= UINT32_C(0x7F800000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0x7F800000)));
      }
      xnn_math_f32_tanh__aarch64_neonfma_rr1_p6_div(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        const uint32_t reference_output = UINT32_C(0x3F800000);
        ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__AARCH64_NEONFMA_RR1_P6_DIV, negative_saturation) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0xC1102CB4); n <= UINT32_C(0xFF800000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0xFF800000)));
      }
      xnn_math_f32_tanh__aarch64_neonfma_rr1_p6_div(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        const uint32_t reference_output = UINT32_C(0xBF800000);
        ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__AARCH64_NEONFMA_RR1_P6_DIV, positive_nan) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
      }
      xnn_math_f32_tanh__aarch64_neonfma_rr1_p6_div(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        ASSERT_TRUE(std::isnan(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__AARCH64_NEONFMA_RR1_P6_DIV, negative_nan) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(UINT32_C(0x80000000) | std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
      }
      xnn_math_f32_tanh__aarch64_neonfma_rr1_p6_div(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        ASSERT_TRUE(std::isnan(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }
#endif  // XNN_ARCH_ARM64

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(TANH__NEONFMA_RR1_P6_NR1RECPS1FMA, positive_saturation) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x41102CB4); n <= UINT32_C(0x7F800000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0x7F800000)));
      }
      xnn_math_f32_tanh__neonfma_rr1_p6_nr1recps1fma(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        const uint32_t reference_output = UINT32_C(0x3F800000);
        ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEONFMA_RR1_P6_NR1RECPS1FMA, negative_saturation) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0xC1102CB4); n <= UINT32_C(0xFF800000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0xFF800000)));
      }
      xnn_math_f32_tanh__neonfma_rr1_p6_nr1recps1fma(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        const uint32_t reference_output = UINT32_C(0xBF800000);
        ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEONFMA_RR1_P6_NR1RECPS1FMA, positive_nan) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
      }
      xnn_math_f32_tanh__neonfma_rr1_p6_nr1recps1fma(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        ASSERT_TRUE(std::isnan(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEONFMA_RR1_P6_NR1RECPS1FMA, negative_nan) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(UINT32_C(0x80000000) | std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
      }
      xnn_math_f32_tanh__neonfma_rr1_p6_nr1recps1fma(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        ASSERT_TRUE(std::isnan(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(TANH__NEONFMA_RR1_P6_NR2FMA, positive_saturation) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x41102CB4); n <= UINT32_C(0x7F800000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0x7F800000)));
      }
      xnn_math_f32_tanh__neonfma_rr1_p6_nr2fma(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        const uint32_t reference_output = UINT32_C(0x3F800000);
        ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEONFMA_RR1_P6_NR2FMA, negative_saturation) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0xC1102CB4); n <= UINT32_C(0xFF800000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0xFF800000)));
      }
      xnn_math_f32_tanh__neonfma_rr1_p6_nr2fma(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        const uint32_t reference_output = UINT32_C(0xBF800000);
        ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEONFMA_RR1_P6_NR2FMA, positive_nan) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
      }
      xnn_math_f32_tanh__neonfma_rr1_p6_nr2fma(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        ASSERT_TRUE(std::isnan(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEONFMA_RR1_P6_NR2FMA, negative_nan) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(UINT32_C(0x80000000) | std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
      }
      xnn_math_f32_tanh__neonfma_rr1_p6_nr2fma(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        ASSERT_TRUE(std::isnan(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(TANH__NEONFMA_RR1_P6_NR2RECPS, positive_saturation) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x41102CB4); n <= UINT32_C(0x7F800000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0x7F800000)));
      }
      xnn_math_f32_tanh__neonfma_rr1_p6_nr2recps(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        const uint32_t reference_output = UINT32_C(0x3F800000);
        ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEONFMA_RR1_P6_NR2RECPS, negative_saturation) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0xC1102CB4); n <= UINT32_C(0xFF800000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0xFF800000)));
      }
      xnn_math_f32_tanh__neonfma_rr1_p6_nr2recps(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        const uint32_t reference_output = UINT32_C(0xBF800000);
        ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEONFMA_RR1_P6_NR2RECPS, positive_nan) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
      }
      xnn_math_f32_tanh__neonfma_rr1_p6_nr2recps(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        ASSERT_TRUE(std::isnan(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEONFMA_RR1_P6_NR2RECPS, negative_nan) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(UINT32_C(0x80000000) | std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
      }
      xnn_math_f32_tanh__neonfma_rr1_p6_nr2recps(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        ASSERT_TRUE(std::isnan(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(TANH__NEON_RR1_P6_NR2RECPS, positive_saturation) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x41102CB4); n <= UINT32_C(0x7F800000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0x7F800000)));
      }
      xnn_math_f32_tanh__neon_rr1_p6_nr2recps(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        const uint32_t reference_output = UINT32_C(0x3F800000);
        ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEON_RR1_P6_NR2RECPS, negative_saturation) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0xC1102CB4); n <= UINT32_C(0xFF800000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0xFF800000)));
      }
      xnn_math_f32_tanh__neon_rr1_p6_nr2recps(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        const uint32_t reference_output = UINT32_C(0xBF800000);
        ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEON_RR1_P6_NR2RECPS, positive_nan) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
      }
      xnn_math_f32_tanh__neon_rr1_p6_nr2recps(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        ASSERT_TRUE(std::isnan(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEON_RR1_P6_NR2RECPS, negative_nan) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(UINT32_C(0x80000000) | std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
      }
      xnn_math_f32_tanh__neon_rr1_p6_nr2recps(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        ASSERT_TRUE(std::isnan(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(TANH__NEON_RR2_P6_NR2RECPS, positive_saturation) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x41102CB4); n <= UINT32_C(0x7F800000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0x7F800000)));
      }
      xnn_math_f32_tanh__neon_rr2_p6_nr2recps(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        const uint32_t reference_output = UINT32_C(0x3F800000);
        ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEON_RR2_P6_NR2RECPS, negative_saturation) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0xC1102CB4); n <= UINT32_C(0xFF800000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0xFF800000)));
      }
      xnn_math_f32_tanh__neon_rr2_p6_nr2recps(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        const uint32_t reference_output = UINT32_C(0xBF800000);
        ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEON_RR2_P6_NR2RECPS, positive_nan) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
      }
      xnn_math_f32_tanh__neon_rr2_p6_nr2recps(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        ASSERT_TRUE(std::isnan(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }

  TEST(TANH__NEON_RR2_P6_NR2RECPS, negative_nan) {
    std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
    std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
    for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
      for (uint32_t i = 0; i < kBlockSize; i++) {
        inputs[i] = uint32_as_float(UINT32_C(0x80000000) | std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
      }
      xnn_math_f32_tanh__neon_rr2_p6_nr2recps(kBlockSize * sizeof(float), inputs.data(), outputs.data());
      for (uint32_t i = 0; i < kBlockSize; i++) {
        ASSERT_TRUE(std::isnan(outputs[i]))
          << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
          << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
      }
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

TEST(TANH__SCALAR_RR1_P6_DIV, positive_saturation) {
  std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
  std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
  for (uint32_t n = UINT32_C(0x41102CB4); n <= UINT32_C(0x7F800000); n += kBlockSize) {
    for (uint32_t i = 0; i < kBlockSize; i++) {
      inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0x7F800000)));
    }
    xnn_math_f32_tanh__scalar_rr1_p6_div(kBlockSize * sizeof(float), inputs.data(), outputs.data());
    for (uint32_t i = 0; i < kBlockSize; i++) {
      const uint32_t reference_output = UINT32_C(0x3F800000);
      ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
        << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
        << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
        << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
    }
  }
}

TEST(TANH__SCALAR_RR1_P6_DIV, negative_saturation) {
  std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
  std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
  for (uint32_t n = UINT32_C(0xC1102CB4); n <= UINT32_C(0xFF800000); n += kBlockSize) {
    for (uint32_t i = 0; i < kBlockSize; i++) {
      inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0xFF800000)));
    }
    xnn_math_f32_tanh__scalar_rr1_p6_div(kBlockSize * sizeof(float), inputs.data(), outputs.data());
    for (uint32_t i = 0; i < kBlockSize; i++) {
      const uint32_t reference_output = UINT32_C(0xBF800000);
      ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
        << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
        << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
        << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
    }
  }
}

TEST(TANH__SCALAR_RR1_P6_DIV, positive_nan) {
  std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
  std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
  for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
    for (uint32_t i = 0; i < kBlockSize; i++) {
      inputs[i] = uint32_as_float(std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
    }
    xnn_math_f32_tanh__scalar_rr1_p6_div(kBlockSize * sizeof(float), inputs.data(), outputs.data());
    for (uint32_t i = 0; i < kBlockSize; i++) {
      ASSERT_TRUE(std::isnan(outputs[i]))
        << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
        << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
    }
  }
}

TEST(TANH__SCALAR_RR1_P6_DIV, negative_nan) {
  std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
  std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
  for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
    for (uint32_t i = 0; i < kBlockSize; i++) {
      inputs[i] = uint32_as_float(UINT32_C(0x80000000) | std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
    }
    xnn_math_f32_tanh__scalar_rr1_p6_div(kBlockSize * sizeof(float), inputs.data(), outputs.data());
    for (uint32_t i = 0; i < kBlockSize; i++) {
      ASSERT_TRUE(std::isnan(outputs[i]))
        << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
        << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
    }
  }
}


TEST(TANH__SCALAR_RR2_P6_DIV, positive_saturation) {
  std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
  std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
  for (uint32_t n = UINT32_C(0x41102CB4); n <= UINT32_C(0x7F800000); n += kBlockSize) {
    for (uint32_t i = 0; i < kBlockSize; i++) {
      inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0x7F800000)));
    }
    xnn_math_f32_tanh__scalar_rr2_p6_div(kBlockSize * sizeof(float), inputs.data(), outputs.data());
    for (uint32_t i = 0; i < kBlockSize; i++) {
      const uint32_t reference_output = UINT32_C(0x3F800000);
      ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
        << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
        << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
        << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
    }
  }
}

TEST(TANH__SCALAR_RR2_P6_DIV, negative_saturation) {
  std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
  std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
  for (uint32_t n = UINT32_C(0xC1102CB4); n <= UINT32_C(0xFF800000); n += kBlockSize) {
    for (uint32_t i = 0; i < kBlockSize; i++) {
      inputs[i] = uint32_as_float(std::min<uint32_t>(n + i, UINT32_C(0xFF800000)));
    }
    xnn_math_f32_tanh__scalar_rr2_p6_div(kBlockSize * sizeof(float), inputs.data(), outputs.data());
    for (uint32_t i = 0; i < kBlockSize; i++) {
      const uint32_t reference_output = UINT32_C(0xBF800000);
      ASSERT_EQ(reference_output, float_as_uint32(outputs[i]))
        << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
        << ", reference = 0x" << std::hex << std::setw(8) << std::setfill('0') << reference_output
        << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
    }
  }
}

TEST(TANH__SCALAR_RR2_P6_DIV, positive_nan) {
  std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
  std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
  for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
    for (uint32_t i = 0; i < kBlockSize; i++) {
      inputs[i] = uint32_as_float(std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
    }
    xnn_math_f32_tanh__scalar_rr2_p6_div(kBlockSize * sizeof(float), inputs.data(), outputs.data());
    for (uint32_t i = 0; i < kBlockSize; i++) {
      ASSERT_TRUE(std::isnan(outputs[i]))
        << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
        << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
    }
  }
}

TEST(TANH__SCALAR_RR2_P6_DIV, negative_nan) {
  std::vector<float, AlignedAllocator<float, 64>> inputs(kBlockSize);
  std::vector<float, AlignedAllocator<float, 64>> outputs(kBlockSize);
  for (uint32_t n = UINT32_C(0x7F800001); n < UINT32_C(0x80000000); n += kBlockSize) {
    for (uint32_t i = 0; i < kBlockSize; i++) {
      inputs[i] = uint32_as_float(UINT32_C(0x80000000) | std::min<uint32_t>(UINT32_C(0x7FFFFFFF), n + i));
    }
    xnn_math_f32_tanh__scalar_rr2_p6_div(kBlockSize * sizeof(float), inputs.data(), outputs.data());
    for (uint32_t i = 0; i < kBlockSize; i++) {
      ASSERT_TRUE(std::isnan(outputs[i]))
        << "input = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(inputs[i])
        << ", optimized = 0x" << std::hex << std::setw(8) << std::setfill('0') << float_as_uint32(outputs[i]);
    }
  }
}
