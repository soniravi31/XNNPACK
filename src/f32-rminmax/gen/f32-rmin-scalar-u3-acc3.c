// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f32-rminmax/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/math.h"
#include "src/xnnpack/reduce.h"

void xnn_f32_rmin_ukernel__scalar_u3_acc3(
    size_t batch,
    const float* input,
    float* output,
    const struct xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(output != NULL);

  const float* i = input;

  float vmin0 = output[0];
  float vmin1 = vmin0;
  float vmin2 = vmin0;
  for (; batch >= 3 * sizeof(float); batch -= 3 * sizeof(float)) {
    const float vt0 = i[0];
    const float vt1 = i[1];
    const float vt2 = i[2];
    i += 3;

    vmin0 = math_min_f32(vmin0, vt0);
    vmin1 = math_min_f32(vmin1, vt1);
    vmin2 = math_min_f32(vmin2, vt2);
  }
  vmin0 = math_min_f32(vmin0, vmin1);
  vmin0 = math_min_f32(vmin0, vmin2);

  if XNN_UNLIKELY(batch != 0) {
    do {
      const float vt = *i++;
      vmin0 = math_min_f32(vmin0, vt);
      batch -= sizeof(float);
    } while (batch != 0);
  }
  output[0] = vmin0;
}
