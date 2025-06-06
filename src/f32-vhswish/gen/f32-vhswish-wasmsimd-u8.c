// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f32-vhswish/wasmsimd.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <wasm_simd128.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/vunary.h"


void xnn_f32_vhswish_ukernel__wasmsimd_u8(
    size_t batch,
    const float* input,
    float* output,
    const struct xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(output != NULL);

  const v128_t vsixth = wasm_f32x4_const_splat(0x1.555556p-3f);
  const v128_t vthree = wasm_f32x4_const_splat(3.0f);
  const v128_t vsix = wasm_f32x4_const_splat(6.0f);
  const v128_t vzero = wasm_i32x4_const_splat(0);

  XNN_FORCE_REALIZATION(vsixth);
  XNN_FORCE_REALIZATION(vthree);
  XNN_FORCE_REALIZATION(vsix);
  // XNN_FORCE_REALIZATION(vzero);

  for (; batch >= 8 * sizeof(float); batch -= 8 * sizeof(float)) {
    v128_t vx0123 = wasm_v128_load(input);
    v128_t vx4567 = wasm_v128_load(input + 4);
    input += 8;

    v128_t vacc0123 = wasm_f32x4_add(vx0123, vthree);
    vx0123 = wasm_f32x4_mul(vx0123, vsixth);
    v128_t vacc4567 = wasm_f32x4_add(vx4567, vthree);
    vx4567 = wasm_f32x4_mul(vx4567, vsixth);

    vacc0123 = wasm_i32x4_max(vacc0123, vzero);
    vacc4567 = wasm_i32x4_max(vacc4567, vzero);

    vacc0123 = wasm_i32x4_min(vacc0123, vsix);
    vacc4567 = wasm_i32x4_min(vacc4567, vsix);

    vacc0123 = wasm_f32x4_mul(vacc0123, vx0123);
    vacc4567 = wasm_f32x4_mul(vacc4567, vx4567);

    wasm_v128_store(output, vacc0123);
    wasm_v128_store(output + 4, vacc4567);
    output += 8;
  }
  for (; batch >= 4 * sizeof(float); batch -= 4 * sizeof(float)) {
    v128_t vx = wasm_v128_load(input);
    input += 4;

    v128_t vacc = wasm_f32x4_add(vx, vthree);
    vx = wasm_f32x4_mul(vx, vsixth);
    vacc = wasm_i32x4_max(vacc, vzero);
    vacc = wasm_i32x4_min(vacc, vsix);
    vacc = wasm_f32x4_mul(vacc, vx);

    wasm_v128_store(output, vacc);
    output += 4;
  }
  if XNN_UNLIKELY(batch != 0) {
    v128_t vx = wasm_v128_load(input);

    v128_t vacc = wasm_f32x4_add(vx, vthree);
    vx = wasm_f32x4_mul(vx, vsixth);
    vacc = wasm_i32x4_max(vacc, vzero);
    vacc = wasm_i32x4_min(vacc, vsix);
    vacc = wasm_f32x4_mul(vacc, vx);

    if (batch & (2 * sizeof(float))) {
      wasm_v128_store64_lane(output, vacc, 0);
      vacc = wasm_v64x2_shuffle(vacc, vacc, 1, 1);
      output += 2;
    }
    if (batch & (1 * sizeof(float))) {
      wasm_v128_store32_lane(output, vacc, 0);
    }
  }
}
