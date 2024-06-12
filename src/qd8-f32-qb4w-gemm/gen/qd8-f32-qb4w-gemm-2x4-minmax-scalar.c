// Auto-generated file. Do not edit!
//   Template: src/qs8-gemm/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <xnnpack/gemm.h>
#include <xnnpack/math.h>


void xnn_qd8_f32_qb4w_gemm_minmax_ukernel_2x4__scalar(
    size_t mr,
    size_t nc,
    size_t kc,
    const int8_t* restrict a,
    size_t a_stride,
    const void* restrict w,
    float* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    const union xnn_f32_qb4w_minmax_params params[restrict XNN_MIN_ELEMENTS(1)],
    const struct xnn_qd8_quantization_params quantization_params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(mr != 0);
  assert(mr <= 2);
  assert(nc != 0);
  assert(kc != 0);
  size_t bl = params->scalar.blocksize;
  assert(bl <= round_up_po2(kc, 2));
  assert(bl != 0);

  const int8_t* a0 = a;
  float* c0 = c;
  const int8_t* a1 = (const int8_t*) ((uintptr_t) a0 + a_stride);
  float* c1 = (float*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr != 2) {
    a1 = a0;
    c1 = c0;
  }

  kc = round_up_po2(kc, 2);
  do {
    const float vksum0 = ((const float*) w)[0];
    const float vksum1 = ((const float*) w)[1];
    const float vksum2 = ((const float*) w)[2];
    const float vksum3 = ((const float*) w)[3];
    const float vinput_zero_point0 = (const float) quantization_params[0].zero_point;
    float vout0x0 = vksum0 * vinput_zero_point0;
    float vout0x1 = vksum1 * vinput_zero_point0;
    float vout0x2 = vksum2 * vinput_zero_point0;
    float vout0x3 = vksum3 * vinput_zero_point0;
    const float vinput_zero_point1 = (const float) quantization_params[1].zero_point;
    float vout1x0 = vksum0 * vinput_zero_point1;
    float vout1x1 = vksum1 * vinput_zero_point1;
    float vout1x2 = vksum2 * vinput_zero_point1;
    float vout1x3 = vksum3 * vinput_zero_point1;
    w = (const float*) w + 4;

    size_t n_blocks = kc / bl;
    for (size_t nb = 0; nb < n_blocks; ++nb) {
      int32_t vacc0x0 = 0;
      int32_t vacc0x1 = 0;
      int32_t vacc0x2 = 0;
      int32_t vacc0x3 = 0;
      int32_t vacc1x0 = 0;
      int32_t vacc1x1 = 0;
      int32_t vacc1x2 = 0;
      int32_t vacc1x3 = 0;
      size_t k = bl;
      for (; k >= 2 * sizeof(uint8_t); k -= 2 * sizeof(uint8_t)) {
        const int32_t va0c0 = (int32_t) a0[0];
        const int32_t va0c1 = (int32_t) a0[1];
        a0 += 2;
        const int32_t va1c0 = (int32_t) a1[0];
        const int32_t va1c1 = (int32_t) a1[1];
        a1 += 2;

        const uint8_t vbi0 = ((const uint8_t*) w)[0];
        const uint8_t vbi1 = ((const uint8_t*) w)[1];
        const uint8_t vbi2 = ((const uint8_t*) w)[2];
        const uint8_t vbi3 = ((const uint8_t*) w)[3];
        w = (const uint8_t*) w + 4;
        const int32_t vb0c0 = (int32_t) (int8_t) (vbi0 << 4);
        const int32_t vb0c1 = (int32_t) (int8_t) (vbi0 & 0xF0);
        const int32_t vb1c0 = (int32_t) (int8_t) (vbi1 << 4);
        const int32_t vb1c1 = (int32_t) (int8_t) (vbi1 & 0xF0);
        const int32_t vb2c0 = (int32_t) (int8_t) (vbi2 << 4);
        const int32_t vb2c1 = (int32_t) (int8_t) (vbi2 & 0xF0);
        const int32_t vb3c0 = (int32_t) (int8_t) (vbi3 << 4);
        const int32_t vb3c1 = (int32_t) (int8_t) (vbi3 & 0xF0);

        vacc0x0 += va0c0 * vb0c0;
        vacc0x1 += va0c0 * vb1c0;
        vacc0x2 += va0c0 * vb2c0;
        vacc0x3 += va0c0 * vb3c0;
        vacc1x0 += va1c0 * vb0c0;
        vacc1x1 += va1c0 * vb1c0;
        vacc1x2 += va1c0 * vb2c0;
        vacc1x3 += va1c0 * vb3c0;
        vacc0x0 += va0c1 * vb0c1;
        vacc0x1 += va0c1 * vb1c1;
        vacc0x2 += va0c1 * vb2c1;
        vacc0x3 += va0c1 * vb3c1;
        vacc1x0 += va1c1 * vb0c1;
        vacc1x1 += va1c1 * vb1c1;
        vacc1x2 += va1c1 * vb2c1;
        vacc1x3 += va1c1 * vb3c1;
    }
    // accumulate in float
      float vf0x0 = vacc0x0;
      const float vfilter_output_scale0 = ((const float*) w)[0];
      float vf0x1 = vacc0x1;
      const float vfilter_output_scale1 = ((const float*) w)[1];
      float vf0x2 = vacc0x2;
      const float vfilter_output_scale2 = ((const float*) w)[2];
      float vf0x3 = vacc0x3;
      const float vfilter_output_scale3 = ((const float*) w)[3];
      float vf1x0 = vacc1x0;
      float vf1x1 = vacc1x1;
      float vf1x2 = vacc1x2;
      float vf1x3 = vacc1x3;

      vf0x0 *= vfilter_output_scale0;
      vout0x0 += vf0x0;
      vf0x1 *= vfilter_output_scale1;
      vout0x1 += vf0x1;
      vf0x2 *= vfilter_output_scale2;
      vout0x2 += vf0x2;
      vf0x3 *= vfilter_output_scale3;
      vout0x3 += vf0x3;
      vf1x0 *= vfilter_output_scale0;
      vout1x0 += vf1x0;
      vf1x1 *= vfilter_output_scale1;
      vout1x1 += vf1x1;
      vf1x2 *= vfilter_output_scale2;
      vout1x2 += vf1x2;
      vf1x3 *= vfilter_output_scale3;
      vout1x3 += vf1x3;
      w = (const float*) w + 4;
    }

    vout0x0 /= 16;
    vout0x1 /= 16;
    vout0x2 /= 16;
    vout0x3 /= 16;
    vout1x0 /= 16;
    vout1x1 /= 16;
    vout1x2 /= 16;
    vout1x3 /= 16;

    const float vinput_scale0 = quantization_params[0].inv_scale;
    vout0x0 *= vinput_scale0;
    vout0x1 *= vinput_scale0;
    vout0x2 *= vinput_scale0;
    vout0x3 *= vinput_scale0;
    const float vinput_scale1 = quantization_params[1].inv_scale;
    vout1x0 *= vinput_scale1;
    vout1x1 *= vinput_scale1;
    vout1x2 *= vinput_scale1;
    vout1x3 *= vinput_scale1;


    const float vbias0 = ((const float*) w)[0];
    vout0x0 += vbias0;
    vout1x0 += vbias0;
    const float vbias1 = ((const float*) w)[1];
    vout0x1 += vbias1;
    vout1x1 += vbias1;
    const float vbias2 = ((const float*) w)[2];
    vout0x2 += vbias2;
    vout1x2 += vbias2;
    const float vbias3 = ((const float*) w)[3];
    vout0x3 += vbias3;
    vout1x3 += vbias3;

    w = (const float*) w + 4;

    const float voutput_min = params->scalar.min;
    vout0x0 = math_max_f32(vout0x0, voutput_min);
    vout1x0 = math_max_f32(vout1x0, voutput_min);
    vout0x1 = math_max_f32(vout0x1, voutput_min);
    vout1x1 = math_max_f32(vout1x1, voutput_min);
    vout0x2 = math_max_f32(vout0x2, voutput_min);
    vout1x2 = math_max_f32(vout1x2, voutput_min);
    vout0x3 = math_max_f32(vout0x3, voutput_min);
    vout1x3 = math_max_f32(vout1x3, voutput_min);

    const float voutput_max = params->scalar.max;
    vout0x0 = math_min_f32(vout0x0, voutput_max);
    vout1x0 = math_min_f32(vout1x0, voutput_max);
    vout0x1 = math_min_f32(vout0x1, voutput_max);
    vout1x1 = math_min_f32(vout1x1, voutput_max);
    vout0x2 = math_min_f32(vout0x2, voutput_max);
    vout1x2 = math_min_f32(vout1x2, voutput_max);
    vout0x3 = math_min_f32(vout0x3, voutput_max);
    vout1x3 = math_min_f32(vout1x3, voutput_max);

    if XNN_LIKELY(nc >= 4) {
      c0[0] = vout0x0;
      c0[1] = vout0x1;
      c0[2] = vout0x2;
      c0[3] = vout0x3;
      c1[0] = vout1x0;
      c1[1] = vout1x1;
      c1[2] = vout1x2;
      c1[3] = vout1x3;

      a0 = (const int8_t*) ((uintptr_t) a0 - kc);
      a1 = (const int8_t*) ((uintptr_t) a1 - kc);

      c0 = (float*) ((uintptr_t) c0 + cn_stride);
      c1 = (float*) ((uintptr_t) c1 + cn_stride);

      nc -= 4;
    } else {
      if (nc & 2) {
        c0[0] = vout0x0;
        c0[1] = vout0x1;
        vout0x0 = vout0x2;
        c0 += 2;
        c1[0] = vout1x0;
        c1[1] = vout1x1;
        vout1x0 = vout1x2;
        c1 += 2;
      }
      if (nc & 1) {
        c0[0] = vout0x0;
        c1[0] = vout1x0;
      }

      nc = 0;
    }
  } while (nc != 0);
}
