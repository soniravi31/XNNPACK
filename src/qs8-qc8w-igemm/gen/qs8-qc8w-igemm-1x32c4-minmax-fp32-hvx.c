// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/qs8-igemm/c4-hvx.c.in
//   Generator: tools/xngen
//
// Copyright 2025 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <math.h>  // for lrintf

#include <hexagon_types.h>
#include <hexagon_protos.h>
#include <hvx_hexagon_protos.h>

#include "src/xnnpack/gemm.h"
#include "src/xnnpack/intrinsics-polyfill.h"  // for Q6_V_vstu_variable
#include "src/xnnpack/math.h"
#include "src/xnnpack/unaligned.h"



// multiply vacc by vscale and return result as int
// vacc is vector of int32
// vscale is vector of floats
// return is vector of int
static HVX_Vector rescale_fp32(HVX_Vector vacc, HVX_Vector vscale)
{
  XNN_ALIGN(128) float vacc_buffer[32];
  XNN_ALIGN(128) float vscale_buffer[32];
  XNN_ALIGN(128) int32_t vresult_buffer[32];

  *((HVX_Vector *)&vacc_buffer) = Q6_Vsf_equals_Vw(vacc);
  *((HVX_Vector *)&vscale_buffer) = vscale;

  for (int i = 0; i < 32; ++i) {
    vresult_buffer[i] = (int32_t)lrintf(vacc_buffer[i] * vscale_buffer[i]);
  }
  return *(HVX_Vector *)&vresult_buffer;
}

void xnn_qs8_qc8w_igemm_minmax_fp32_ukernel_1x32c4__hvx(
    size_t mr,
    size_t nc,
    size_t kc,
    size_t ks,
    const int8_t** restrict a,
    const void* restrict w,
    int8_t* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    size_t a_offset,
    const int8_t* zero,
    const union xnn_qs8_qc8w_conv_minmax_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(mr != 0);
  assert(mr <= 1);
  assert(nc != 0);
  assert(kc != 0);
  assert(ks != 0);
  assert(ks % (1 * sizeof(void*)) == 0);
  assert(a_offset % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);


  kc = round_up_po2(kc, 4 * sizeof(int8_t));
  int8_t* c0 = c;

  const HVX_Vector voutput_zero_point = Q6_Vh_vsplat_R(params->fp32_scalar.output_zero_point);
  const HVX_Vector voutput_min = Q6_Vb_vsplat_R(params->fp32_scalar.output_min);
  const HVX_Vector voutput_max = Q6_Vb_vsplat_R(params->fp32_scalar.output_max);

  do {
    HVX_Vector vacc0x32 = *((HVX_Vector*)w); w = (const int32_t*) w + 32;

    size_t p = ks;
    do {
      const int8_t* restrict a0 = a[0];
      if XNN_UNPREDICTABLE(a0 != zero) {
        a0 = (const int8_t*) ((uintptr_t) a0 + a_offset);
      }
      a += 1;

      size_t k = kc;
      for (; k >= 4 * sizeof(int8_t); k -= 4 * sizeof(int8_t)) {
        const HVX_Vector va0x0123 = Q6_V_vsplat_R(unaligned_load_s32(a0)); a0 += 4;

        const HVX_Vector vb32x0123 = *((HVX_Vector *)((int8_t *)w)); w = (const int8_t*) w + 128;

        vacc0x32 = Q6_Vw_vrmpyacc_VwVbVb(vacc0x32, va0x0123, vb32x0123);
      }

      p -= 1 * sizeof(void*);
    } while (p != 0);

    const HVX_Vector vscale32 = *((HVX_Vector *)w); w = (const float*) w + 32;
    vacc0x32 = rescale_fp32(vacc0x32, vscale32);

    HVX_Vector vout0x32 = Q6_Vh_vpack_VwVw_sat(vacc0x32, vacc0x32);

    vout0x32 = Q6_Vh_vadd_VhVh_sat(vout0x32, voutput_zero_point);

    vout0x32 = Q6_Vb_vpack_VhVh_sat(vout0x32, vout0x32);

    vout0x32 = Q6_Vb_vmax_VbVb(vout0x32, voutput_min);

    vout0x32 = Q6_Vb_vmin_VbVb(vout0x32, voutput_max);

    if XNN_LIKELY(nc >= 32) {
      Q6_V_vstu_variable(c0, 32, vout0x32);
      c0 = (int8_t*) ((uintptr_t) c0 + cn_stride);

      a = (const int8_t**restrict) ((uintptr_t) a - ks);
      nc -= 32;
    } else {
      // Prepare mask for valid 8-bit elements (depends on nc).
      Q6_V_vstu_variable(c0, nc, vout0x32);
      nc = 0;
    }
  } while (nc != 0);
}
