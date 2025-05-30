// clang-format off
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#ifndef XNN_UKERNEL_WITH_PARAMS
#define XNN_UKERNEL_WITH_PARAMS(arch_flags, ukernel, channel_tile, primary_tile, datatype, params_type, init_params) \
    XNN_UKERNEL(arch_flags, ukernel, channel_tile, primary_tile, datatype)
#define XNN_DEFINED_UKERNEL_WITH_PARAMS
#endif

#ifndef XNN_UKERNEL
#define XNN_UKERNEL(arch_flags, ukernel, channel_tile, primary_tile, datatype) \
    XNN_UKERNEL_WITH_PARAMS(arch_flags, ukernel, channel_tile, primary_tile, datatype, void, /*init_params=*/nullptr)
#define XNN_DEFINED_UKERNEL
#endif

// arch_flags, ukernel, channel_tile, primary_tile, datatype, params_type, init_params

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
XNN_UKERNEL_WITH_PARAMS(xnn_arch_arm_neon, xnn_s8_maxpool_minmax_ukernel_9p__neon_u16, 16, 9, int8_t, struct xnn_s8_minmax_params, xnn_init_s8_minmax_scalar_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
XNN_UKERNEL_WITH_PARAMS(xnn_arch_x86_sse4_1, xnn_s8_maxpool_minmax_ukernel_9p__sse41_u16, 16, 9, int8_t, struct xnn_s8_minmax_params, xnn_init_s8_minmax_scalar_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
XNN_UKERNEL_WITH_PARAMS(0, xnn_s8_maxpool_minmax_ukernel_9p__wasmsimd_u16, 16, 9, int8_t, struct xnn_s8_minmax_params, xnn_init_s8_minmax_scalar_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD

XNN_UKERNEL_WITH_PARAMS(0, xnn_s8_maxpool_minmax_ukernel_9p__scalar_u1, 1, 9, int8_t, struct xnn_s8_minmax_params, xnn_init_s8_minmax_scalar_params)


#ifdef XNN_DEFINED_UKERNEL_WITH_PARAMS
#undef XNN_DEFINED_UKERNEL_WITH_PARAMS
#undef XNN_UKERNEL_WITH_PARAMS
#endif

#ifdef XNN_DEFINED_UKERNEL
#undef XNN_DEFINED_UKERNEL
#undef XNN_UKERNEL
#endif

