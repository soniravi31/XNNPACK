// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/qs8-gemm/c4-hvx.c.in
//   Generator: tools/xngen
//
// Copyright 2025 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

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
static XNN_INLINE HVX_Vector rescale_fp32(HVX_Vector vacc, HVX_Vector vscale)
{
  const HVX_Vector vaccf = Q6_Vsf_equals_Vw(vacc);
  const HVX_Vector vscaledqf = Q6_Vqf32_vmpy_VsfVsf(vaccf, vscale);

  // Create a vector of `0.5f` with the same sign as the entries of `a`.
  const HVX_Vector vhalf = Q6_V_vsplat_R(0.5f);
  const HVX_Vector vsign_mask = Q6_V_vsplat_R(-0.0f);
  const HVX_Vector vsigned_half = Q6_V_vor_VV(Q6_V_vand_VV(vaccf, vsign_mask), vhalf);
  const HVX_Vector vresult = Q6_Vw_equals_Vsf(Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(vscaledqf, vsigned_half)));
  return vresult;
}

void xnn_qs8_qc8w_gemm_minmax_fp32_ukernel_2x64c4__hvx(
    size_t mr,
    size_t nc,
    size_t kc,
    const int8_t* restrict a,
    size_t a_stride,
    const void* restrict w,
    int8_t* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    const union xnn_qs8_qc8w_conv_minmax_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(mr != 0);
  assert(mr <= 2);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  kc = round_up_po2(kc, 4 * sizeof(int8_t));
  const int8_t* a0 = a;
  int8_t* c0 = c;
  const int8_t* a1 = (const int8_t*) ((uintptr_t) a0 + a_stride);
  int8_t* c1 = (int8_t*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr != 2) {
    a1 = a0;
    c1 = c0;
  }

  const HVX_Vector voutput_zero_point = Q6_Vh_vsplat_R(params->fp32_scalar.output_zero_point);
  const HVX_Vector voutput_min = Q6_Vb_vsplat_R(params->fp32_scalar.output_min);
  const HVX_Vector voutput_max = Q6_Vb_vsplat_R(params->fp32_scalar.output_max);

  do {
    HVX_Vector vacc0x0 = *((HVX_Vector *) w); w = (const int8_t*) w + 128;
    HVX_Vector vacc0x1 = *((HVX_Vector *) w); w = (const int8_t*) w + 128;
    HVX_Vector vacc1x0 = vacc0x0;
    HVX_Vector vacc1x1 = vacc0x1;

    size_t k = kc;
    for (; k >= 4 * sizeof(int8_t); k -= 4 * sizeof(int8_t)) {
      const HVX_Vector va0x0123 = Q6_V_vsplat_R(unaligned_load_s32(a0)); a0 += 4;
      const HVX_Vector va1x0123 = Q6_V_vsplat_R(unaligned_load_s32(a1)); a1 += 4;

      const HVX_Vector vb0x0123 = *((HVX_Vector *) w); w = (const int8_t*) w + 128;
      const HVX_Vector vb1x0123 = *((HVX_Vector *) w); w = (const int8_t*) w + 128;

      vacc0x0 = Q6_Vw_vrmpyacc_VwVbVb(vacc0x0, va0x0123, vb0x0123);
      vacc0x1 = Q6_Vw_vrmpyacc_VwVbVb(vacc0x1, va0x0123, vb1x0123);
      vacc1x0 = Q6_Vw_vrmpyacc_VwVbVb(vacc1x0, va1x0123, vb0x0123);
      vacc1x1 = Q6_Vw_vrmpyacc_VwVbVb(vacc1x1, va1x0123, vb1x0123);
    }

    const HVX_Vector vscale0 = *((HVX_Vector *) w); w = (const int8_t*) w + 128;
    vacc0x0 = rescale_fp32(vacc0x0, vscale0);
    vacc1x0 = rescale_fp32(vacc1x0, vscale0);
    const HVX_Vector vscale1 = *((HVX_Vector *) w); w = (const int8_t*) w + 128;
    vacc0x1 = rescale_fp32(vacc0x1, vscale1);
    vacc1x1 = rescale_fp32(vacc1x1, vscale1);

    HVX_Vector vout0x0 = Q6_Vh_vpack_VwVw_sat(vacc0x1, vacc0x0);
    HVX_Vector vout1x0 = Q6_Vh_vpack_VwVw_sat(vacc1x1, vacc1x0);

    vout0x0 = Q6_Vh_vadd_VhVh_sat(vout0x0, voutput_zero_point);
    vout1x0 = Q6_Vh_vadd_VhVh_sat(vout1x0, voutput_zero_point);

    HVX_Vector vout0 = Q6_Vb_vpack_VhVh_sat(vout0x0, vout0x0);
    HVX_Vector vout1 = Q6_Vb_vpack_VhVh_sat(vout1x0, vout1x0);

    vout0 = Q6_Vb_vmax_VbVb(vout0, voutput_min);
    vout1 = Q6_Vb_vmax_VbVb(vout1, voutput_min);

    vout0 = Q6_Vb_vmin_VbVb(vout0, voutput_max);
    vout1 = Q6_Vb_vmin_VbVb(vout1, voutput_max);

    if XNN_LIKELY(nc >= 64) {
      Q6_V_vstu_variable(c0, 64, vout0);
      c0 = (int8_t*) ((uintptr_t) c0 + cn_stride);
      a0 = (const int8_t*) ((uintptr_t) a0 - kc);
      Q6_V_vstu_variable(c1, 64, vout1);
      c1 = (int8_t*) ((uintptr_t) c1 + cn_stride);
      a1 = (const int8_t*) ((uintptr_t) a1 - kc);

      nc -= 64;
    } else {
      // Prepare mask for valid 8-bit elements (depends on nc).
      Q6_V_vstu_variable(c0, nc, vout0);
      Q6_V_vstu_variable(c1, nc, vout1);
      nc = 0;
    }
  } while (nc != 0);
}
