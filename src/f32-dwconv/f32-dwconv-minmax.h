// clang-format off
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

// Arguments are:
// XNN_UKERNEL(arch, name, c_block, pipelined, cr, kr, datatype, weights_type,params_type, init_fn)

#if XNN_ARCH_ARM64 && XNN_ENABLE_ASSEMBLY
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_9p4c__asm_aarch64_neonfma, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_9p4c__asm_aarch64_neonfma_cortex_a55, 4, true, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
#endif  // XNN_ARCH_ARM64

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_3p4c__neon, 4, false, 4, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_3p4c__neon_acc2, 4, false, 4, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_3p4c__neonfma, 4, false, 4, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_3p4c__neonfma_acc2, 4, false, 4, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_3p8c__neon, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_3p8c__neon_acc2, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_3p8c__neonfma, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_3p8c__neonfma_acc2, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_3p16c__neon, 16, false, 16, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_3p16c__neon_acc2, 16, false, 16, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_3p16c__neonfma, 16, false, 16, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_3p16c__neonfma_acc2, 16, false, 16, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_4p4c__neon, 4, false, 4, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_4p4c__neon_acc2, 4, false, 4, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_4p4c__neonfma, 4, false, 4, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_4p4c__neonfma_acc2, 4, false, 4, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_4p8c__neon, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_4p8c__neon_acc2, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_4p8c__neonfma, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_4p8c__neonfma_acc2, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_4p16c__neon, 16, false, 16, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_4p16c__neon_acc2, 16, false, 16, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_4p16c__neonfma, 16, false, 16, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_4p16c__neonfma_acc2, 16, false, 16, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_9p4c__neon, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_9p4c__neon_acc2, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_9p4c__neonfma, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_9p4c__neonfma_acc2, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_9p8c__neon, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_9p8c__neon_acc2, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_9p8c__neonfma, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_9p8c__neonfma_acc2, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_9p16c__neon, 16, false, 16, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_9p16c__neon_acc2, 16, false, 16, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_9p16c__neonfma, 16, false, 16, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_9p16c__neonfma_acc2, 16, false, 16, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_25p4c__neon, 4, false, 4, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_25p4c__neon_acc2, 4, false, 4, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_25p4c__neonfma, 4, false, 4, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_25p4c__neonfma_acc2, 4, false, 4, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_25p8c__neon, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_25p8c__neon_acc2, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_25p8c__neonfma, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_25p8c__neonfma_acc2, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_25p16c__neon, 16, false, 16, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_dwconv_minmax_ukernel_25p16c__neon_acc2, 16, false, 16, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_25p16c__neonfma, 16, false, 16, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon_fma, xnn_f32_dwconv_minmax_ukernel_25p16c__neonfma_acc2, 16, false, 16, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p4c__sse, 4, false, 4, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p4c__sse_acc2, 4, false, 4, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p8c__sse, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p8c__sse_acc2, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p4c__sse, 4, false, 4, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p4c__sse_acc2, 4, false, 4, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p8c__sse, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p8c__sse_acc2, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p4c__sse, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p4c__sse_acc2, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p8c__sse, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p8c__sse_acc2, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p4c__sse, 4, false, 4, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p4c__sse_acc2, 4, false, 4, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p8c__sse, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p8c__sse_acc2, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_3p8c__avx, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_3p8c__avx_acc2, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_3p16c__avx, 16, false, 16, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_3p16c__avx_acc2, 16, false, 16, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_4p8c__avx, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_4p8c__avx_acc2, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_4p16c__avx, 16, false, 16, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_4p16c__avx_acc2, 16, false, 16, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_9p8c__avx, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_9p8c__avx_acc2, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_9p16c__avx, 16, false, 16, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_9p16c__avx_acc2, 16, false, 16, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_25p8c__avx, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_25p8c__avx_acc2, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_25p16c__avx, 16, false, 16, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_dwconv_minmax_ukernel_25p16c__avx_acc2, 16, false, 16, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_3p8c__fma3, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_3p8c__fma3_acc2, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_3p16c__fma3, 16, false, 16, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_3p16c__fma3_acc2, 16, false, 16, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_4p8c__fma3, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_4p8c__fma3_acc2, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_4p16c__fma3, 16, false, 16, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_4p16c__fma3_acc2, 16, false, 16, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_9p8c__fma3, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_9p8c__fma3_acc2, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_9p16c__fma3, 16, false, 16, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_9p16c__fma3_acc2, 16, false, 16, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_25p8c__fma3, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_25p8c__fma3_acc2, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_25p16c__fma3, 16, false, 16, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_fma3, xnn_f32_dwconv_minmax_ukernel_25p16c__fma3_acc2, 16, false, 16, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ENABLE_AVX512F && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_3p16c__avx512f, 16, false, 16, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_3p16c__avx512f_acc2, 16, false, 16, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_3p32c__avx512f, 32, false, 32, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_3p32c__avx512f_acc2, 32, false, 32, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_4p16c__avx512f, 16, false, 16, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_4p16c__avx512f_acc2, 16, false, 16, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_4p32c__avx512f, 32, false, 32, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_4p32c__avx512f_acc2, 32, false, 32, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_9p16c__avx512f, 16, false, 16, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_9p16c__avx512f_acc2, 16, false, 16, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_9p32c__avx512f, 32, false, 32, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_9p32c__avx512f_acc2, 32, false, 32, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_25p16c__avx512f, 16, false, 16, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_25p16c__avx512f_acc2, 16, false, 16, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_25p32c__avx512f, 32, false, 32, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_dwconv_minmax_ukernel_25p32c__avx512f_acc2, 32, false, 32, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p4c__wasmsimd_arm, 4, false, 4, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p4c__wasmsimd_arm_acc2, 4, false, 4, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p4c__wasmsimd_x86, 4, false, 4, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p4c__wasmsimd_x86_acc2, 4, false, 4, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p8c__wasmsimd_arm, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p8c__wasmsimd_arm_acc2, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p8c__wasmsimd_x86, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p8c__wasmsimd_x86_acc2, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p4c__wasmsimd_arm, 4, false, 4, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p4c__wasmsimd_arm_acc2, 4, false, 4, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p4c__wasmsimd_x86, 4, false, 4, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p4c__wasmsimd_x86_acc2, 4, false, 4, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p8c__wasmsimd_arm, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p8c__wasmsimd_arm_acc2, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p8c__wasmsimd_x86, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p8c__wasmsimd_x86_acc2, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p4c__wasmsimd_arm, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p4c__wasmsimd_arm_acc2, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p4c__wasmsimd_x86, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p4c__wasmsimd_x86_acc2, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p8c__wasmsimd_arm, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p8c__wasmsimd_arm_acc2, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p8c__wasmsimd_x86, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p8c__wasmsimd_x86_acc2, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p4c__wasmsimd_arm, 4, false, 4, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p4c__wasmsimd_arm_acc2, 4, false, 4, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p4c__wasmsimd_x86, 4, false, 4, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p4c__wasmsimd_x86_acc2, 4, false, 4, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p8c__wasmsimd_arm, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p8c__wasmsimd_arm_acc2, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p8c__wasmsimd_x86, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p8c__wasmsimd_x86_acc2, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD

#if XNN_ARCH_WASMRELAXEDSIMD
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p4c__wasmrelaxedsimd, 4, false, 4, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p4c__wasmrelaxedsimd_acc2, 4, false, 4, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p4c__wasmrelaxedsimd_fma, 4, false, 4, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p4c__wasmrelaxedsimd_fma_acc2, 4, false, 4, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p8c__wasmrelaxedsimd, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p8c__wasmrelaxedsimd_acc2, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p8c__wasmrelaxedsimd_fma, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p8c__wasmrelaxedsimd_fma_acc2, 8, false, 8, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p4c__wasmrelaxedsimd, 4, false, 4, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p4c__wasmrelaxedsimd_acc2, 4, false, 4, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p4c__wasmrelaxedsimd_fma, 4, false, 4, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p4c__wasmrelaxedsimd_fma_acc2, 4, false, 4, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p8c__wasmrelaxedsimd, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p8c__wasmrelaxedsimd_acc2, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p8c__wasmrelaxedsimd_fma, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p8c__wasmrelaxedsimd_fma_acc2, 8, false, 8, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p4c__wasmrelaxedsimd, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p4c__wasmrelaxedsimd_acc2, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p4c__wasmrelaxedsimd_fma, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p4c__wasmrelaxedsimd_fma_acc2, 4, false, 4, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p8c__wasmrelaxedsimd, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p8c__wasmrelaxedsimd_acc2, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p8c__wasmrelaxedsimd_fma, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p8c__wasmrelaxedsimd_fma_acc2, 8, false, 8, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p4c__wasmrelaxedsimd, 4, false, 4, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p4c__wasmrelaxedsimd_acc2, 4, false, 4, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p4c__wasmrelaxedsimd_fma, 4, false, 4, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p4c__wasmrelaxedsimd_fma_acc2, 4, false, 4, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p8c__wasmrelaxedsimd, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p8c__wasmrelaxedsimd_acc2, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p8c__wasmrelaxedsimd_fma, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p8c__wasmrelaxedsimd_fma_acc2, 8, false, 8, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
#endif  // XNN_ARCH_WASMRELAXEDSIMD

#if XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p1c__wasm, 1, false, 1, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p1c__wasm_acc2, 1, false, 1, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p2c__wasm, 2, false, 2, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p2c__wasm_acc2, 2, false, 2, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p1c__wasm, 1, false, 1, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p1c__wasm_acc2, 1, false, 1, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p2c__wasm, 2, false, 2, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p2c__wasm_acc2, 2, false, 2, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p1c__wasm, 1, false, 1, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p1c__wasm_acc2, 1, false, 1, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p2c__wasm, 2, false, 2, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p2c__wasm_acc2, 2, false, 2, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p1c__wasm, 1, false, 1, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p1c__wasm_acc2, 1, false, 1, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p2c__wasm, 2, false, 2, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p2c__wasm_acc2, 2, false, 2, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
#endif  // XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD

#if XNN_ENABLE_RISCV_VECTOR && XNN_ARCH_RISCV
XNN_UKERNEL(xnn_arch_riscv_vector, xnn_f32_dwconv_minmax_ukernel_3p8vc__rvv, 8 * (xnn_init_hardware_config()->vlenb / sizeof(float)), false, 8 * (xnn_init_hardware_config()->vlenb / sizeof(float)), 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_riscv_vector, xnn_f32_dwconv_minmax_ukernel_4p8vc__rvv, 8 * (xnn_init_hardware_config()->vlenb / sizeof(float)), false, 8 * (xnn_init_hardware_config()->vlenb / sizeof(float)), 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_riscv_vector, xnn_f32_dwconv_minmax_ukernel_9p8vc__rvv, 8 * (xnn_init_hardware_config()->vlenb / sizeof(float)), false, 8 * (xnn_init_hardware_config()->vlenb / sizeof(float)), 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(xnn_arch_riscv_vector, xnn_f32_dwconv_minmax_ukernel_25p8vc__rvv, 8 * (xnn_init_hardware_config()->vlenb / sizeof(float)), false, 8 * (xnn_init_hardware_config()->vlenb / sizeof(float)), 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
#endif  // XNN_ENABLE_RISCV_VECTOR && XNN_ARCH_RISCV

XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p1c__scalar, 1, false, 1, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p1c__scalar_acc2, 1, false, 1, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p2c__scalar, 2, false, 2, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_3p2c__scalar_acc2, 2, false, 2, 3, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p1c__scalar, 1, false, 1, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p1c__scalar_acc2, 1, false, 1, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p2c__scalar, 2, false, 2, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_4p2c__scalar_acc2, 2, false, 2, 4, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p1c__scalar, 1, false, 1, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p1c__scalar_acc2, 1, false, 1, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p2c__scalar, 2, false, 2, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_9p2c__scalar_acc2, 2, false, 2, 9, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p1c__scalar, 1, false, 1, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p1c__scalar_acc2, 1, false, 1, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p2c__scalar, 2, false, 2, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)
XNN_UKERNEL(0, xnn_f32_dwconv_minmax_ukernel_25p2c__scalar_acc2, 2, false, 2, 25, float, float, struct xnn_f32_minmax_params, xnn_init_f32_minmax_scalar_params)

