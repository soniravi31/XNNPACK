// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/qs8-gemm/4x16-aarch64-neon-mlal-lane-ld64.S.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.


#include "src/xnnpack/assembly.h"

# void xnn_qu8_gemm_minmax_rndnu_ukernel_4x16__asm_aarch64_neon_mlal_lane_ld64_prfm(
#     size_t mr,                 x0
#     size_t nc,                 x1
#     size_t kc,                 x2 / x0
#     const uint8_t* restrict a,  x3
#     size_t a_stride,           x4
#     const void* restrict w,    x5
#     uint8_t* restrict c,        x6
#     size_t cm_stride,          x7
#     size_t cn_stride,          [sp] -> x12
#     const union xnn_qs8_conv_minmax_params params)  [sp + 8] -> x11

# params structure is 20 bytes
#  struct {
#    uint8_t kernel_zero_point;
#    uint8_t padding[3];
#    int32_t right_pre_shift;
#    int32_t multiplier;
#    int32_t right_post_shift;
#    int16_t output_zero_point;
#    uint8_t output_min;
#    uint8_t output_max;
#  } rndnu_neon;
#
# d8-d15, x19-x30 need to be preserved if used. x18 is reserved by the OS.

// Register usage
// A0  x3 v0
// A1 x15 v1
// A2 x13 v2
// A3  x4 v3
// B   x5 v4  v5
// C0  x6 v16 v20 v24 v28
// C1  x8 v17 v21 v25 v29
// C2  x9 v18 v22 v26 v30
// C3  x7 v19 v23 v27 v31
# zero_point  v7
# unused v8 v9 v10 v11 v12 v13 v14 v15

BEGIN_FUNCTION xnn_qu8_gemm_minmax_rndnu_ukernel_4x16__asm_aarch64_neon_mlal_lane_ld64_prfm

        # Clamp A and C pointers
        CMP         x0, 2                   // if mr < 2
        LDP         x12, x11, [sp]          // Load cn_stride, params
        ADD         x15, x3, x4             // a1 = a0 + a_stride
        ADD         x8, x6, x7              // c1 = c0 + cm_stride
        CSEL        x15, x3, x15, LO        //   a1 = a0
        CSEL        x8, x6,  x8, LO         //   c1 = c0

        ADD         x13, x15, x4            // a2 = a1 + a_stride
        ADD         x9,  x8, x7             // c2 = c1 + cm_stride
                                            // if mr <= 2
        CSEL        x13, x15, x13, LS       //   a2 = a1
        CSEL        x9,  x8,  x9, LS        //   c2 = c1

        CMP         x0, 4                   // if mr < 4
        ADD         x4, x13, x4             // a3 = a2 + a_stride
        ADD         x7,  x9, x7             // c3 = c2 + cm_stride
        CSEL        x4, x13, x4, LO         //   a3 = a2
        CSEL        x7,  x9, x7, LO         //   c3 = c2
        LD1R        {v7.16b}, [x11]       // kernel_zero_point
        ADD         x11, x11, 4           // skip padding

        .p2align    3
0:
        # Load initial bias from w into accumulators
        LDP         q16, q20, [x5], 32
        MOV         v17.16b, v16.16b
        MOV         v18.16b, v16.16b
        LDP         q24, q28, [x5], 32
        MOV         v19.16b, v16.16b
        MOV         v21.16b, v20.16b
        MOV         v22.16b, v20.16b
        MOV         v23.16b, v20.16b
        SUBS        x0, x2, 8               // k = kc - 8
        MOV         v25.16b, v24.16b
        MOV         v26.16b, v24.16b
        MOV         v27.16b, v24.16b
        MOV         v29.16b, v28.16b
        MOV         v30.16b, v28.16b
        MOV         v31.16b, v28.16b
        # Is there at least 8 bytes for main loop?
        B.LO        3f

        # Main loop - 8 bytes of A
        .p2align    3
1:
        LD1         {v0.8b},  [x3], 8
        LDP         d4, d5, [x5], 16
        LD1         {v1.8b}, [x15], 8
        LD1         {v2.8b}, [x13], 8
        LD1         {v3.8b},  [x4], 8
        UXTL    v0.8h, v0.8b
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        UXTL    v1.8h, v1.8b
        UXTL    v2.8h, v2.8b
        UXTL    v3.8h, v3.8b
        SMLAL       v16.4s, v4.4h, v0.h[0]
        SMLAL2      v20.4s, v4.8h, v0.h[0]
        PRFM        PLDL1KEEP, [x13, 128]
        SMLAL       v24.4s, v5.4h, v0.h[0]
        SMLAL2      v28.4s, v5.8h, v0.h[0]
        PRFM        PLDL1KEEP, [x15, 128]
        SMLAL       v17.4s, v4.4h, v1.h[0]
        SMLAL2      v21.4s, v4.8h, v1.h[0]
        PRFM        PLDL1KEEP, [x3, 128]
        SMLAL       v25.4s, v5.4h, v1.h[0]
        SMLAL2      v29.4s, v5.8h, v1.h[0]
        PRFM        PLDL1KEEP, [x4, 128]
        SMLAL       v18.4s, v4.4h, v2.h[0]
        SMLAL2      v22.4s, v4.8h, v2.h[0]
        PRFM        PLDL1KEEP, [x5, 448]
        SMLAL       v26.4s, v5.4h, v2.h[0]
        SMLAL2      v30.4s, v5.8h, v2.h[0]
        PRFM        PLDL1KEEP, [x5, 512]
        SMLAL       v19.4s, v4.4h, v3.h[0]
        SMLAL2      v23.4s, v4.8h, v3.h[0]
        SMLAL       v27.4s, v5.4h, v3.h[0]
        SMLAL2      v31.4s, v5.8h, v3.h[0]

        LDP         d4, d5, [x5], 16
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        SMLAL       v16.4s, v4.4h, v0.h[1]
        SMLAL2      v20.4s, v4.8h, v0.h[1]
        SMLAL       v24.4s, v5.4h, v0.h[1]
        SMLAL2      v28.4s, v5.8h, v0.h[1]
        SMLAL       v17.4s, v4.4h, v1.h[1]
        SMLAL2      v21.4s, v4.8h, v1.h[1]
        SMLAL       v25.4s, v5.4h, v1.h[1]
        SMLAL2      v29.4s, v5.8h, v1.h[1]
        SMLAL       v18.4s, v4.4h, v2.h[1]
        SMLAL2      v22.4s, v4.8h, v2.h[1]
        SMLAL       v26.4s, v5.4h, v2.h[1]
        SMLAL2      v30.4s, v5.8h, v2.h[1]
        SMLAL       v19.4s, v4.4h, v3.h[1]
        SMLAL2      v23.4s, v4.8h, v3.h[1]
        SMLAL       v27.4s, v5.4h, v3.h[1]
        SMLAL2      v31.4s, v5.8h, v3.h[1]

        LDP         d4, d5, [x5], 16
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        SMLAL       v16.4s, v4.4h, v0.h[2]
        SMLAL2      v20.4s, v4.8h, v0.h[2]
        SMLAL       v24.4s, v5.4h, v0.h[2]
        SMLAL2      v28.4s, v5.8h, v0.h[2]
        SMLAL       v17.4s, v4.4h, v1.h[2]
        SMLAL2      v21.4s, v4.8h, v1.h[2]
        SMLAL       v25.4s, v5.4h, v1.h[2]
        SMLAL2      v29.4s, v5.8h, v1.h[2]
        SMLAL       v18.4s, v4.4h, v2.h[2]
        SMLAL2      v22.4s, v4.8h, v2.h[2]
        SMLAL       v26.4s, v5.4h, v2.h[2]
        SMLAL2      v30.4s, v5.8h, v2.h[2]
        SMLAL       v19.4s, v4.4h, v3.h[2]
        SMLAL2      v23.4s, v4.8h, v3.h[2]
        SMLAL       v27.4s, v5.4h, v3.h[2]
        SMLAL2      v31.4s, v5.8h, v3.h[2]

        LDP         d4, d5, [x5], 16
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        SMLAL       v16.4s, v4.4h, v0.h[3]
        SMLAL2      v20.4s, v4.8h, v0.h[3]
        SMLAL       v24.4s, v5.4h, v0.h[3]
        SMLAL2      v28.4s, v5.8h, v0.h[3]
        SMLAL       v17.4s, v4.4h, v1.h[3]
        SMLAL2      v21.4s, v4.8h, v1.h[3]
        SMLAL       v25.4s, v5.4h, v1.h[3]
        SMLAL2      v29.4s, v5.8h, v1.h[3]
        SMLAL       v18.4s, v4.4h, v2.h[3]
        SMLAL2      v22.4s, v4.8h, v2.h[3]
        SMLAL       v26.4s, v5.4h, v2.h[3]
        SMLAL2      v30.4s, v5.8h, v2.h[3]
        SMLAL       v19.4s, v4.4h, v3.h[3]
        SMLAL2      v23.4s, v4.8h, v3.h[3]
        SMLAL       v27.4s, v5.4h, v3.h[3]
        SMLAL2      v31.4s, v5.8h, v3.h[3]

        LDP         d4, d5, [x5], 16
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        SMLAL       v16.4s, v4.4h, v0.h[4]
        SMLAL2      v20.4s, v4.8h, v0.h[4]
        SMLAL       v24.4s, v5.4h, v0.h[4]
        SMLAL2      v28.4s, v5.8h, v0.h[4]
        SMLAL       v17.4s, v4.4h, v1.h[4]
        SMLAL2      v21.4s, v4.8h, v1.h[4]
        SMLAL       v25.4s, v5.4h, v1.h[4]
        SMLAL2      v29.4s, v5.8h, v1.h[4]
        SMLAL       v18.4s, v4.4h, v2.h[4]
        SMLAL2      v22.4s, v4.8h, v2.h[4]
        SMLAL       v26.4s, v5.4h, v2.h[4]
        SMLAL2      v30.4s, v5.8h, v2.h[4]
        SMLAL       v19.4s, v4.4h, v3.h[4]
        SMLAL2      v23.4s, v4.8h, v3.h[4]
        SMLAL       v27.4s, v5.4h, v3.h[4]
        SMLAL2      v31.4s, v5.8h, v3.h[4]

        LDP         d4, d5, [x5], 16
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        SMLAL       v16.4s, v4.4h, v0.h[5]
        SMLAL2      v20.4s, v4.8h, v0.h[5]
        SMLAL       v24.4s, v5.4h, v0.h[5]
        SMLAL2      v28.4s, v5.8h, v0.h[5]
        SMLAL       v17.4s, v4.4h, v1.h[5]
        SMLAL2      v21.4s, v4.8h, v1.h[5]
        SMLAL       v25.4s, v5.4h, v1.h[5]
        SMLAL2      v29.4s, v5.8h, v1.h[5]
        SMLAL       v18.4s, v4.4h, v2.h[5]
        SMLAL2      v22.4s, v4.8h, v2.h[5]
        SMLAL       v26.4s, v5.4h, v2.h[5]
        SMLAL2      v30.4s, v5.8h, v2.h[5]
        SMLAL       v19.4s, v4.4h, v3.h[5]
        SMLAL2      v23.4s, v4.8h, v3.h[5]
        SMLAL       v27.4s, v5.4h, v3.h[5]
        SMLAL2      v31.4s, v5.8h, v3.h[5]

        LDP         d4, d5, [x5], 16
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        SMLAL       v16.4s, v4.4h, v0.h[6]
        SMLAL2      v20.4s, v4.8h, v0.h[6]
        SMLAL       v24.4s, v5.4h, v0.h[6]
        SMLAL2      v28.4s, v5.8h, v0.h[6]
        SMLAL       v17.4s, v4.4h, v1.h[6]
        SMLAL2      v21.4s, v4.8h, v1.h[6]
        SMLAL       v25.4s, v5.4h, v1.h[6]
        SMLAL2      v29.4s, v5.8h, v1.h[6]
        SMLAL       v18.4s, v4.4h, v2.h[6]
        SMLAL2      v22.4s, v4.8h, v2.h[6]
        SMLAL       v26.4s, v5.4h, v2.h[6]
        SMLAL2      v30.4s, v5.8h, v2.h[6]
        SMLAL       v19.4s, v4.4h, v3.h[6]
        SMLAL2      v23.4s, v4.8h, v3.h[6]
        SMLAL       v27.4s, v5.4h, v3.h[6]
        SMLAL2      v31.4s, v5.8h, v3.h[6]

        LDP         d4, d5, [x5], 16
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        SMLAL       v16.4s, v4.4h, v0.h[7]
        SMLAL2      v20.4s, v4.8h, v0.h[7]
        SMLAL       v24.4s, v5.4h, v0.h[7]
        SMLAL2      v28.4s, v5.8h, v0.h[7]
        SMLAL       v17.4s, v4.4h, v1.h[7]
        SMLAL2      v21.4s, v4.8h, v1.h[7]
        SMLAL       v25.4s, v5.4h, v1.h[7]
        SMLAL2      v29.4s, v5.8h, v1.h[7]
        SMLAL       v18.4s, v4.4h, v2.h[7]
        SMLAL2      v22.4s, v4.8h, v2.h[7]
        SMLAL       v26.4s, v5.4h, v2.h[7]
        SMLAL2      v30.4s, v5.8h, v2.h[7]
        SMLAL       v19.4s, v4.4h, v3.h[7]
        SMLAL2      v23.4s, v4.8h, v3.h[7]
        SMLAL       v27.4s, v5.4h, v3.h[7]
        SMLAL2      v31.4s, v5.8h, v3.h[7]

        SUBS        x0, x0, 8
        B.HS        1b

        AND         x0, x2, 7               // kc remainder 0 to 7
        # Is there a remainder?- 1 to 7 bytes of A
        CBNZ        x0, 3f

2:
        # Apply params - preshift, scale, postshift, bias and clamp
        LD1R        {v4.4s}, [x11], 4
        SQSHL       v16.4s, v16.4s, v4.4s   // shift to upper bits
        SQSHL       v17.4s, v17.4s, v4.4s
        SQSHL       v18.4s, v18.4s, v4.4s
        SQSHL       v19.4s, v19.4s, v4.4s
        SQSHL       v20.4s, v20.4s, v4.4s
        SQSHL       v21.4s, v21.4s, v4.4s
        SQSHL       v22.4s, v22.4s, v4.4s
        SQSHL       v23.4s, v23.4s, v4.4s
        LD1R        {v5.4s}, [x11], 4
        SQSHL       v24.4s, v24.4s, v4.4s
        SQSHL       v25.4s, v25.4s, v4.4s
        SQSHL       v26.4s, v26.4s, v4.4s
        SQSHL       v27.4s, v27.4s, v4.4s
        SQSHL       v28.4s, v28.4s, v4.4s
        SQSHL       v29.4s, v29.4s, v4.4s
        SQSHL       v30.4s, v30.4s, v4.4s
        SQSHL       v31.4s, v31.4s, v4.4s
        LD1R        {v6.4s}, [x11], 4
        SQDMULH     v16.4s, v16.4s, v5.4s   // scale without rounding
        SQDMULH     v17.4s, v17.4s, v5.4s
        SQDMULH     v18.4s, v18.4s, v5.4s
        SQDMULH     v19.4s, v19.4s, v5.4s
        SQDMULH     v20.4s, v20.4s, v5.4s
        SQDMULH     v21.4s, v21.4s, v5.4s
        SQDMULH     v22.4s, v22.4s, v5.4s
        SQDMULH     v23.4s, v23.4s, v5.4s
        SQDMULH     v24.4s, v24.4s, v5.4s
        SQDMULH     v25.4s, v25.4s, v5.4s
        SQDMULH     v26.4s, v26.4s, v5.4s
        SQDMULH     v27.4s, v27.4s, v5.4s
        SQDMULH     v28.4s, v28.4s, v5.4s
        SQDMULH     v29.4s, v29.4s, v5.4s
        SQDMULH     v30.4s, v30.4s, v5.4s
        SQDMULH     v31.4s, v31.4s, v5.4s
        SRSHL       v16.4s, v16.4s, v6.4s   // signed rounding shift left
        SRSHL       v17.4s, v17.4s, v6.4s
        SRSHL       v18.4s, v18.4s, v6.4s
        SRSHL       v19.4s, v19.4s, v6.4s
        SRSHL       v20.4s, v20.4s, v6.4s
        SRSHL       v21.4s, v21.4s, v6.4s
        SRSHL       v22.4s, v22.4s, v6.4s
        SRSHL       v23.4s, v23.4s, v6.4s
        SRSHL       v24.4s, v24.4s, v6.4s
        SRSHL       v25.4s, v25.4s, v6.4s
        SRSHL       v26.4s, v26.4s, v6.4s
        SRSHL       v27.4s, v27.4s, v6.4s
        SRSHL       v28.4s, v28.4s, v6.4s
        SRSHL       v29.4s, v29.4s, v6.4s
        SRSHL       v30.4s, v30.4s, v6.4s
        SRSHL       v31.4s, v31.4s, v6.4s

        SQXTN       v16.4h, v16.4s
        SQXTN       v17.4h, v17.4s
        SQXTN       v18.4h, v18.4s
        SQXTN       v19.4h, v19.4s
        SQXTN       v24.4h, v24.4s
        SQXTN       v25.4h, v25.4s
        SQXTN       v26.4h, v26.4s
        SQXTN       v27.4h, v27.4s
        LD1R        {v6.8h}, [x11], 2       // add bias

        SQXTN2      v16.8h, v20.4s
        SQXTN2      v17.8h, v21.4s
        SQXTN2      v18.8h, v22.4s
        SQXTN2      v19.8h, v23.4s
        SQXTN2      v24.8h, v28.4s
        SQXTN2      v25.8h, v29.4s
        SQXTN2      v26.8h, v30.4s
        SQXTN2      v27.8h, v31.4s

        SQADD       v16.8h, v16.8h, v6.8h
        SQADD       v17.8h, v17.8h, v6.8h
        SQADD       v18.8h, v18.8h, v6.8h
        SQADD       v19.8h, v19.8h, v6.8h
        SQADD       v24.8h, v24.8h, v6.8h
        SQADD       v25.8h, v25.8h, v6.8h
        SQADD       v26.8h, v26.8h, v6.8h
        SQADD       v27.8h, v27.8h, v6.8h
        LD1R        {v4.16b}, [x11], 1      // clamp min value

        SQXTUN   v0.8b, v16.8h
        SQXTUN   v1.8b, v17.8h
        SQXTUN   v2.8b, v18.8h
        SQXTUN   v3.8b, v19.8h
        LD1R        {v5.16b}, [x11]         // clamp max value
        SQXTUN2  v0.16b, v24.8h
        SQXTUN2  v1.16b, v25.8h
        SQXTUN2  v2.16b, v26.8h
        SQXTUN2  v3.16b, v27.8h
        SUB         x11, x11, 15               // rewind params pointer

        UMAX    v0.16b, v0.16b, v4.16b
        UMAX    v1.16b, v1.16b, v4.16b
        UMAX    v2.16b, v2.16b, v4.16b
        UMAX    v3.16b, v3.16b, v4.16b
        SUBS        x1, x1, 16
        UMIN    v0.16b, v0.16b, v5.16b
        UMIN    v1.16b, v1.16b, v5.16b
        UMIN    v2.16b, v2.16b, v5.16b
        UMIN    v3.16b, v3.16b, v5.16b
        B.LO        4f

        # Store full 4 x 16
        ST1         {v0.16b}, [x6], x12
        SUB         x3,  x3, x2             // a0 -= kc
        ST1         {v1.16b}, [x8], x12
        SUB         x15, x15, x2            // a1 -= kc
        ST1         {v2.16b}, [x9], x12
        SUB         x13, x13, x2            // a2 -= kc
        ST1         {v3.16b}, [x7], x12
        SUB         x4,  x4, x2             // a3 -= kc
        B.NE        0b
        RET

        # Remainder- 1 to 7 bytes of A
        .p2align    3
3:
        AND         x0, x2, 7               // kc remainder 1 to 7

        LD1         {v0.8b},  [x3], x0
        LDP         d4, d5, [x5], 16
        LD1         {v1.8b}, [x15], x0
        LD1         {v2.8b}, [x13], x0
        LD1         {v3.8b},  [x4], x0
        UXTL    v0.8h, v0.8b
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        UXTL    v1.8h, v1.8b
        UXTL    v2.8h, v2.8b
        UXTL    v3.8h, v3.8b
        SMLAL       v16.4s, v4.4h, v0.h[0]
        SMLAL2      v20.4s, v4.8h, v0.h[0]
        SMLAL       v24.4s, v5.4h, v0.h[0]
        SMLAL2      v28.4s, v5.8h, v0.h[0]
        SMLAL       v17.4s, v4.4h, v1.h[0]
        SMLAL2      v21.4s, v4.8h, v1.h[0]
        SMLAL       v25.4s, v5.4h, v1.h[0]
        SMLAL2      v29.4s, v5.8h, v1.h[0]
        SMLAL       v18.4s, v4.4h, v2.h[0]
        SMLAL2      v22.4s, v4.8h, v2.h[0]
        SMLAL       v26.4s, v5.4h, v2.h[0]
        SMLAL2      v30.4s, v5.8h, v2.h[0]
        SMLAL       v19.4s, v4.4h, v3.h[0]
        SMLAL2      v23.4s, v4.8h, v3.h[0]
        SMLAL       v27.4s, v5.4h, v3.h[0]
        SMLAL2      v31.4s, v5.8h, v3.h[0]
        CMP         x0, 2
        B.LO        2b

        LDP         d4, d5, [x5], 16
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        SMLAL       v16.4s, v4.4h, v0.h[1]
        SMLAL2      v20.4s, v4.8h, v0.h[1]
        SMLAL       v24.4s, v5.4h, v0.h[1]
        SMLAL2      v28.4s, v5.8h, v0.h[1]
        SMLAL       v17.4s, v4.4h, v1.h[1]
        SMLAL2      v21.4s, v4.8h, v1.h[1]
        SMLAL       v25.4s, v5.4h, v1.h[1]
        SMLAL2      v29.4s, v5.8h, v1.h[1]
        SMLAL       v18.4s, v4.4h, v2.h[1]
        SMLAL2      v22.4s, v4.8h, v2.h[1]
        SMLAL       v26.4s, v5.4h, v2.h[1]
        SMLAL2      v30.4s, v5.8h, v2.h[1]
        SMLAL       v19.4s, v4.4h, v3.h[1]
        SMLAL2      v23.4s, v4.8h, v3.h[1]
        SMLAL       v27.4s, v5.4h, v3.h[1]
        SMLAL2      v31.4s, v5.8h, v3.h[1]
        B.EQ        2b

        LDP         d4, d5, [x5], 16
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        SMLAL       v16.4s, v4.4h, v0.h[2]
        SMLAL2      v20.4s, v4.8h, v0.h[2]
        SMLAL       v24.4s, v5.4h, v0.h[2]
        SMLAL2      v28.4s, v5.8h, v0.h[2]
        SMLAL       v17.4s, v4.4h, v1.h[2]
        SMLAL2      v21.4s, v4.8h, v1.h[2]
        SMLAL       v25.4s, v5.4h, v1.h[2]
        SMLAL2      v29.4s, v5.8h, v1.h[2]
        SMLAL       v18.4s, v4.4h, v2.h[2]
        SMLAL2      v22.4s, v4.8h, v2.h[2]
        SMLAL       v26.4s, v5.4h, v2.h[2]
        SMLAL2      v30.4s, v5.8h, v2.h[2]
        SMLAL       v19.4s, v4.4h, v3.h[2]
        SMLAL2      v23.4s, v4.8h, v3.h[2]
        SMLAL       v27.4s, v5.4h, v3.h[2]
        SMLAL2      v31.4s, v5.8h, v3.h[2]
        CMP         x0, 4
        B.LO        2b

        LDP         d4, d5, [x5], 16
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        SMLAL       v16.4s, v4.4h, v0.h[3]
        SMLAL2      v20.4s, v4.8h, v0.h[3]
        SMLAL       v24.4s, v5.4h, v0.h[3]
        SMLAL2      v28.4s, v5.8h, v0.h[3]
        SMLAL       v17.4s, v4.4h, v1.h[3]
        SMLAL2      v21.4s, v4.8h, v1.h[3]
        SMLAL       v25.4s, v5.4h, v1.h[3]
        SMLAL2      v29.4s, v5.8h, v1.h[3]
        SMLAL       v18.4s, v4.4h, v2.h[3]
        SMLAL2      v22.4s, v4.8h, v2.h[3]
        SMLAL       v26.4s, v5.4h, v2.h[3]
        SMLAL2      v30.4s, v5.8h, v2.h[3]
        SMLAL       v19.4s, v4.4h, v3.h[3]
        SMLAL2      v23.4s, v4.8h, v3.h[3]
        SMLAL       v27.4s, v5.4h, v3.h[3]
        SMLAL2      v31.4s, v5.8h, v3.h[3]
        B.EQ        2b

        LDP         d4, d5, [x5], 16
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        SMLAL       v16.4s, v4.4h, v0.h[4]
        SMLAL2      v20.4s, v4.8h, v0.h[4]
        SMLAL       v24.4s, v5.4h, v0.h[4]
        SMLAL2      v28.4s, v5.8h, v0.h[4]
        SMLAL       v17.4s, v4.4h, v1.h[4]
        SMLAL2      v21.4s, v4.8h, v1.h[4]
        SMLAL       v25.4s, v5.4h, v1.h[4]
        SMLAL2      v29.4s, v5.8h, v1.h[4]
        SMLAL       v18.4s, v4.4h, v2.h[4]
        SMLAL2      v22.4s, v4.8h, v2.h[4]
        SMLAL       v26.4s, v5.4h, v2.h[4]
        SMLAL2      v30.4s, v5.8h, v2.h[4]
        SMLAL       v19.4s, v4.4h, v3.h[4]
        SMLAL2      v23.4s, v4.8h, v3.h[4]
        SMLAL       v27.4s, v5.4h, v3.h[4]
        SMLAL2      v31.4s, v5.8h, v3.h[4]
        CMP         x0, 6
        B.LO        2b

        LDP         d4, d5, [x5], 16
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        SMLAL       v16.4s, v4.4h, v0.h[5]
        SMLAL2      v20.4s, v4.8h, v0.h[5]
        SMLAL       v24.4s, v5.4h, v0.h[5]
        SMLAL2      v28.4s, v5.8h, v0.h[5]
        SMLAL       v17.4s, v4.4h, v1.h[5]
        SMLAL2      v21.4s, v4.8h, v1.h[5]
        SMLAL       v25.4s, v5.4h, v1.h[5]
        SMLAL2      v29.4s, v5.8h, v1.h[5]
        SMLAL       v18.4s, v4.4h, v2.h[5]
        SMLAL2      v22.4s, v4.8h, v2.h[5]
        SMLAL       v26.4s, v5.4h, v2.h[5]
        SMLAL2      v30.4s, v5.8h, v2.h[5]
        SMLAL       v19.4s, v4.4h, v3.h[5]
        SMLAL2      v23.4s, v4.8h, v3.h[5]
        SMLAL       v27.4s, v5.4h, v3.h[5]
        SMLAL2      v31.4s, v5.8h, v3.h[5]
        B.EQ        2b

        LDP         d4, d5, [x5], 16
        USUBL       v4.8h, v4.8b, v7.8b
        USUBL       v5.8h, v5.8b, v7.8b
        SMLAL       v16.4s, v4.4h, v0.h[6]
        SMLAL2      v20.4s, v4.8h, v0.h[6]
        SMLAL       v24.4s, v5.4h, v0.h[6]
        SMLAL2      v28.4s, v5.8h, v0.h[6]
        SMLAL       v17.4s, v4.4h, v1.h[6]
        SMLAL2      v21.4s, v4.8h, v1.h[6]
        SMLAL       v25.4s, v5.4h, v1.h[6]
        SMLAL2      v29.4s, v5.8h, v1.h[6]
        SMLAL       v18.4s, v4.4h, v2.h[6]
        SMLAL2      v22.4s, v4.8h, v2.h[6]
        SMLAL       v26.4s, v5.4h, v2.h[6]
        SMLAL2      v30.4s, v5.8h, v2.h[6]
        SMLAL       v19.4s, v4.4h, v3.h[6]
        SMLAL2      v23.4s, v4.8h, v3.h[6]
        SMLAL       v27.4s, v5.4h, v3.h[6]
        SMLAL2      v31.4s, v5.8h, v3.h[6]
        B           2b

        # Store odd width
        .p2align    3
4:
        TBZ         x1, 3, 5f
        STR         d0, [x6], 8
        STR         d1, [x8], 8
        DUP         d0, v0.d[1]
        DUP         d1, v1.d[1]
        STR         d2, [x9], 8
        STR         d3, [x7], 8
        DUP         d2, v2.d[1]
        DUP         d3, v3.d[1]
5:
        TBZ         x1, 2, 6f
        STR         s0, [x6], 4
        STR         s1, [x8], 4
        DUP         s0, v0.s[1]
        DUP         s1, v1.s[1]
        STR         s2, [x9], 4
        STR         s3, [x7], 4
        DUP         s2, v2.s[1]
        DUP         s3, v3.s[1]
6:
        TBZ         x1, 1, 7f
        STR         h0, [x6], 2
        STR         h1, [x8], 2
        DUP         h0, v0.h[1]
        DUP         h1, v1.h[1]
        STR         h2, [x9], 2
        STR         h3, [x7], 2
        DUP         h2, v2.h[1]
        DUP         h3, v3.h[1]
7:
        TBZ         x1, 0, 8f
        STR         b0, [x6]
        STR         b1, [x8]
        STR         b2, [x9]
        STR         b3, [x7]
8:
        RET

END_FUNCTION xnn_qu8_gemm_minmax_rndnu_ukernel_4x16__asm_aarch64_neon_mlal_lane_ld64_prfm

#ifdef __ELF__
.section ".note.GNU-stack","",%progbits
#endif
