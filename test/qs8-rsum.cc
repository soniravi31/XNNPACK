// clang-format off
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: test/qs8-rsum.yaml
//   Generator: tools/generate-reduce-test.py


#include <gtest/gtest.h>
#include "src/xnnpack/common.h"
#include "src/xnnpack/isa-checks.h"
#include "src/xnnpack/microparams-init.h"
#include "src/xnnpack/reduce.h"
#include "test/rsum-microkernel-tester.h"


TEST(QS8_RSUM__SCALAR_U1, batch_eq_1) {
  RSumMicrokernelTester()
    .batch_size(1)
    .Test(xnn_qs8_rsum_ukernel__scalar_u1);
}

TEST(QS8_RSUM__SCALAR_U1, batch_gt_1) {
  for (size_t batch_size = 2; batch_size < 10; batch_size++) {
    RSumMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_qs8_rsum_ukernel__scalar_u1);
  }
}

TEST(QS8_RSUM__SCALAR_U1, scale) {
  for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
    RSumMicrokernelTester()
      .batch_size(2)
      .scale(scale)
      .Test(xnn_qs8_rsum_ukernel__scalar_u1);
  }
}

TEST(QS8_RSUM__SCALAR_U1, overflow_accumulator) {
  RSumMicrokernelTester()
    .batch_size(128)
    .Test(xnn_qs8_rsum_ukernel__scalar_u1);
}

TEST(QS8_RSUM__SCALAR_U2, batch_eq_2) {
  RSumMicrokernelTester()
    .batch_size(2)
    .Test(xnn_qs8_rsum_ukernel__scalar_u2);
}

TEST(QS8_RSUM__SCALAR_U2, batch_div_2) {
  for (size_t batch_size = 4; batch_size < 20; batch_size += 2) {
    RSumMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_qs8_rsum_ukernel__scalar_u2);
  }
}

TEST(QS8_RSUM__SCALAR_U2, batch_lt_2) {
  for (size_t batch_size = 1; batch_size < 2; batch_size++) {
    RSumMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_qs8_rsum_ukernel__scalar_u2);
  }
}

TEST(QS8_RSUM__SCALAR_U2, batch_gt_2) {
  for (size_t batch_size = 3; batch_size < 4; batch_size++) {
    RSumMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_qs8_rsum_ukernel__scalar_u2);
  }
}

TEST(QS8_RSUM__SCALAR_U2, scale) {
  for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
    RSumMicrokernelTester()
      .batch_size(3)
      .scale(scale)
      .Test(xnn_qs8_rsum_ukernel__scalar_u2);
  }
}

TEST(QS8_RSUM__SCALAR_U2, overflow_accumulator) {
  RSumMicrokernelTester()
    .batch_size(256)
    .Test(xnn_qs8_rsum_ukernel__scalar_u2);
}

TEST(QS8_RSUM__SCALAR_U4, batch_eq_4) {
  RSumMicrokernelTester()
    .batch_size(4)
    .Test(xnn_qs8_rsum_ukernel__scalar_u4);
}

TEST(QS8_RSUM__SCALAR_U4, batch_div_4) {
  for (size_t batch_size = 8; batch_size < 40; batch_size += 4) {
    RSumMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_qs8_rsum_ukernel__scalar_u4);
  }
}

TEST(QS8_RSUM__SCALAR_U4, batch_lt_4) {
  for (size_t batch_size = 1; batch_size < 4; batch_size++) {
    RSumMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_qs8_rsum_ukernel__scalar_u4);
  }
}

TEST(QS8_RSUM__SCALAR_U4, batch_gt_4) {
  for (size_t batch_size = 5; batch_size < 8; batch_size++) {
    RSumMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_qs8_rsum_ukernel__scalar_u4);
  }
}

TEST(QS8_RSUM__SCALAR_U4, scale) {
  for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
    RSumMicrokernelTester()
      .batch_size(5)
      .scale(scale)
      .Test(xnn_qs8_rsum_ukernel__scalar_u4);
  }
}

TEST(QS8_RSUM__SCALAR_U4, overflow_accumulator) {
  RSumMicrokernelTester()
    .batch_size(512)
    .Test(xnn_qs8_rsum_ukernel__scalar_u4);
}

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(QS8_RSUM__NEON_U16, batch_eq_16) {
    TEST_REQUIRES_ARM_NEON;
    RSumMicrokernelTester()
      .batch_size(16)
      .Test(xnn_qs8_rsum_ukernel__neon_u16);
  }

  TEST(QS8_RSUM__NEON_U16, batch_div_16) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neon_u16);
    }
  }

  TEST(QS8_RSUM__NEON_U16, batch_lt_16) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neon_u16);
    }
  }

  TEST(QS8_RSUM__NEON_U16, batch_gt_16) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neon_u16);
    }
  }

  TEST(QS8_RSUM__NEON_U16, scale) {
    TEST_REQUIRES_ARM_NEON;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(17)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__neon_u16);
    }
  }

  TEST(QS8_RSUM__NEON_U16, overflow_accumulator) {
    TEST_REQUIRES_ARM_NEON;
    RSumMicrokernelTester()
      .batch_size(2048)
      .Test(xnn_qs8_rsum_ukernel__neon_u16);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(QS8_RSUM__NEON_U32_ACC2, batch_eq_32) {
    TEST_REQUIRES_ARM_NEON;
    RSumMicrokernelTester()
      .batch_size(32)
      .Test(xnn_qs8_rsum_ukernel__neon_u32_acc2);
  }

  TEST(QS8_RSUM__NEON_U32_ACC2, batch_div_32) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 64; batch_size < 320; batch_size += 32) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neon_u32_acc2);
    }
  }

  TEST(QS8_RSUM__NEON_U32_ACC2, batch_lt_32) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neon_u32_acc2);
    }
  }

  TEST(QS8_RSUM__NEON_U32_ACC2, batch_gt_32) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 33; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neon_u32_acc2);
    }
  }

  TEST(QS8_RSUM__NEON_U32_ACC2, scale) {
    TEST_REQUIRES_ARM_NEON;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(33)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__neon_u32_acc2);
    }
  }

  TEST(QS8_RSUM__NEON_U32_ACC2, overflow_accumulator) {
    TEST_REQUIRES_ARM_NEON;
    RSumMicrokernelTester()
      .batch_size(4096)
      .Test(xnn_qs8_rsum_ukernel__neon_u32_acc2);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(QS8_RSUM__NEON_U64_ACC2, batch_eq_64) {
    TEST_REQUIRES_ARM_NEON;
    RSumMicrokernelTester()
      .batch_size(64)
      .Test(xnn_qs8_rsum_ukernel__neon_u64_acc2);
  }

  TEST(QS8_RSUM__NEON_U64_ACC2, batch_div_64) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 128; batch_size < 640; batch_size += 64) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neon_u64_acc2);
    }
  }

  TEST(QS8_RSUM__NEON_U64_ACC2, batch_lt_64) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neon_u64_acc2);
    }
  }

  TEST(QS8_RSUM__NEON_U64_ACC2, batch_gt_64) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 65; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neon_u64_acc2);
    }
  }

  TEST(QS8_RSUM__NEON_U64_ACC2, scale) {
    TEST_REQUIRES_ARM_NEON;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(65)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__neon_u64_acc2);
    }
  }

  TEST(QS8_RSUM__NEON_U64_ACC2, overflow_accumulator) {
    TEST_REQUIRES_ARM_NEON;
    RSumMicrokernelTester()
      .batch_size(8192)
      .Test(xnn_qs8_rsum_ukernel__neon_u64_acc2);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(QS8_RSUM__NEON_U64_ACC4, batch_eq_64) {
    TEST_REQUIRES_ARM_NEON;
    RSumMicrokernelTester()
      .batch_size(64)
      .Test(xnn_qs8_rsum_ukernel__neon_u64_acc4);
  }

  TEST(QS8_RSUM__NEON_U64_ACC4, batch_div_64) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 128; batch_size < 640; batch_size += 64) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neon_u64_acc4);
    }
  }

  TEST(QS8_RSUM__NEON_U64_ACC4, batch_lt_64) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neon_u64_acc4);
    }
  }

  TEST(QS8_RSUM__NEON_U64_ACC4, batch_gt_64) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 65; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neon_u64_acc4);
    }
  }

  TEST(QS8_RSUM__NEON_U64_ACC4, scale) {
    TEST_REQUIRES_ARM_NEON;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(65)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__neon_u64_acc4);
    }
  }

  TEST(QS8_RSUM__NEON_U64_ACC4, overflow_accumulator) {
    TEST_REQUIRES_ARM_NEON;
    RSumMicrokernelTester()
      .batch_size(8192)
      .Test(xnn_qs8_rsum_ukernel__neon_u64_acc4);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ENABLE_ARM_DOTPROD && (XNN_ARCH_ARM || XNN_ARCH_ARM64)
  TEST(QS8_RSUM__NEONDOT_U16, batch_eq_16) {
    TEST_REQUIRES_ARM_NEON_DOT;
    RSumMicrokernelTester()
      .batch_size(16)
      .Test(xnn_qs8_rsum_ukernel__neondot_u16);
  }

  TEST(QS8_RSUM__NEONDOT_U16, batch_div_16) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neondot_u16);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U16, batch_lt_16) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neondot_u16);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U16, batch_gt_16) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neondot_u16);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U16, scale) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(17)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__neondot_u16);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U16, overflow_accumulator) {
    TEST_REQUIRES_ARM_NEON_DOT;
    RSumMicrokernelTester()
      .batch_size(2048)
      .Test(xnn_qs8_rsum_ukernel__neondot_u16);
  }
#endif  // XNN_ENABLE_ARM_DOTPROD && (XNN_ARCH_ARM || XNN_ARCH_ARM64)


#if XNN_ENABLE_ARM_DOTPROD && (XNN_ARCH_ARM || XNN_ARCH_ARM64)
  TEST(QS8_RSUM__NEONDOT_U32_ACC2, batch_eq_32) {
    TEST_REQUIRES_ARM_NEON_DOT;
    RSumMicrokernelTester()
      .batch_size(32)
      .Test(xnn_qs8_rsum_ukernel__neondot_u32_acc2);
  }

  TEST(QS8_RSUM__NEONDOT_U32_ACC2, batch_div_32) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (size_t batch_size = 64; batch_size < 320; batch_size += 32) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neondot_u32_acc2);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U32_ACC2, batch_lt_32) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (size_t batch_size = 1; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neondot_u32_acc2);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U32_ACC2, batch_gt_32) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (size_t batch_size = 33; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neondot_u32_acc2);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U32_ACC2, scale) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(33)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__neondot_u32_acc2);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U32_ACC2, overflow_accumulator) {
    TEST_REQUIRES_ARM_NEON_DOT;
    RSumMicrokernelTester()
      .batch_size(4096)
      .Test(xnn_qs8_rsum_ukernel__neondot_u32_acc2);
  }
#endif  // XNN_ENABLE_ARM_DOTPROD && (XNN_ARCH_ARM || XNN_ARCH_ARM64)


#if XNN_ENABLE_ARM_DOTPROD && (XNN_ARCH_ARM || XNN_ARCH_ARM64)
  TEST(QS8_RSUM__NEONDOT_U64_ACC2, batch_eq_64) {
    TEST_REQUIRES_ARM_NEON_DOT;
    RSumMicrokernelTester()
      .batch_size(64)
      .Test(xnn_qs8_rsum_ukernel__neondot_u64_acc2);
  }

  TEST(QS8_RSUM__NEONDOT_U64_ACC2, batch_div_64) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (size_t batch_size = 128; batch_size < 640; batch_size += 64) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neondot_u64_acc2);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U64_ACC2, batch_lt_64) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (size_t batch_size = 1; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neondot_u64_acc2);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U64_ACC2, batch_gt_64) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (size_t batch_size = 65; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neondot_u64_acc2);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U64_ACC2, scale) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(65)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__neondot_u64_acc2);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U64_ACC2, overflow_accumulator) {
    TEST_REQUIRES_ARM_NEON_DOT;
    RSumMicrokernelTester()
      .batch_size(8192)
      .Test(xnn_qs8_rsum_ukernel__neondot_u64_acc2);
  }
#endif  // XNN_ENABLE_ARM_DOTPROD && (XNN_ARCH_ARM || XNN_ARCH_ARM64)


#if XNN_ENABLE_ARM_DOTPROD && (XNN_ARCH_ARM || XNN_ARCH_ARM64)
  TEST(QS8_RSUM__NEONDOT_U64_ACC4, batch_eq_64) {
    TEST_REQUIRES_ARM_NEON_DOT;
    RSumMicrokernelTester()
      .batch_size(64)
      .Test(xnn_qs8_rsum_ukernel__neondot_u64_acc4);
  }

  TEST(QS8_RSUM__NEONDOT_U64_ACC4, batch_div_64) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (size_t batch_size = 128; batch_size < 640; batch_size += 64) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neondot_u64_acc4);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U64_ACC4, batch_lt_64) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (size_t batch_size = 1; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neondot_u64_acc4);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U64_ACC4, batch_gt_64) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (size_t batch_size = 65; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__neondot_u64_acc4);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U64_ACC4, scale) {
    TEST_REQUIRES_ARM_NEON_DOT;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(65)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__neondot_u64_acc4);
    }
  }

  TEST(QS8_RSUM__NEONDOT_U64_ACC4, overflow_accumulator) {
    TEST_REQUIRES_ARM_NEON_DOT;
    RSumMicrokernelTester()
      .batch_size(8192)
      .Test(xnn_qs8_rsum_ukernel__neondot_u64_acc4);
  }
#endif  // XNN_ENABLE_ARM_DOTPROD && (XNN_ARCH_ARM || XNN_ARCH_ARM64)


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(QS8_RSUM__SSSE3_U16, batch_eq_16) {
    TEST_REQUIRES_X86_SSSE3;
    RSumMicrokernelTester()
      .batch_size(16)
      .Test(xnn_qs8_rsum_ukernel__ssse3_u16);
  }

  TEST(QS8_RSUM__SSSE3_U16, batch_div_16) {
    TEST_REQUIRES_X86_SSSE3;
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u16);
    }
  }

  TEST(QS8_RSUM__SSSE3_U16, batch_lt_16) {
    TEST_REQUIRES_X86_SSSE3;
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u16);
    }
  }

  TEST(QS8_RSUM__SSSE3_U16, batch_gt_16) {
    TEST_REQUIRES_X86_SSSE3;
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u16);
    }
  }

  TEST(QS8_RSUM__SSSE3_U16, scale) {
    TEST_REQUIRES_X86_SSSE3;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(17)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u16);
    }
  }

  TEST(QS8_RSUM__SSSE3_U16, overflow_accumulator) {
    TEST_REQUIRES_X86_SSSE3;
    RSumMicrokernelTester()
      .batch_size(2048)
      .Test(xnn_qs8_rsum_ukernel__ssse3_u16);
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(QS8_RSUM__SSSE3_U32_ACC2, batch_eq_32) {
    TEST_REQUIRES_X86_SSSE3;
    RSumMicrokernelTester()
      .batch_size(32)
      .Test(xnn_qs8_rsum_ukernel__ssse3_u32_acc2);
  }

  TEST(QS8_RSUM__SSSE3_U32_ACC2, batch_div_32) {
    TEST_REQUIRES_X86_SSSE3;
    for (size_t batch_size = 64; batch_size < 320; batch_size += 32) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u32_acc2);
    }
  }

  TEST(QS8_RSUM__SSSE3_U32_ACC2, batch_lt_32) {
    TEST_REQUIRES_X86_SSSE3;
    for (size_t batch_size = 1; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u32_acc2);
    }
  }

  TEST(QS8_RSUM__SSSE3_U32_ACC2, batch_gt_32) {
    TEST_REQUIRES_X86_SSSE3;
    for (size_t batch_size = 33; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u32_acc2);
    }
  }

  TEST(QS8_RSUM__SSSE3_U32_ACC2, scale) {
    TEST_REQUIRES_X86_SSSE3;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(33)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u32_acc2);
    }
  }

  TEST(QS8_RSUM__SSSE3_U32_ACC2, overflow_accumulator) {
    TEST_REQUIRES_X86_SSSE3;
    RSumMicrokernelTester()
      .batch_size(4096)
      .Test(xnn_qs8_rsum_ukernel__ssse3_u32_acc2);
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(QS8_RSUM__SSSE3_U64_ACC2, batch_eq_64) {
    TEST_REQUIRES_X86_SSSE3;
    RSumMicrokernelTester()
      .batch_size(64)
      .Test(xnn_qs8_rsum_ukernel__ssse3_u64_acc2);
  }

  TEST(QS8_RSUM__SSSE3_U64_ACC2, batch_div_64) {
    TEST_REQUIRES_X86_SSSE3;
    for (size_t batch_size = 128; batch_size < 640; batch_size += 64) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u64_acc2);
    }
  }

  TEST(QS8_RSUM__SSSE3_U64_ACC2, batch_lt_64) {
    TEST_REQUIRES_X86_SSSE3;
    for (size_t batch_size = 1; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u64_acc2);
    }
  }

  TEST(QS8_RSUM__SSSE3_U64_ACC2, batch_gt_64) {
    TEST_REQUIRES_X86_SSSE3;
    for (size_t batch_size = 65; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u64_acc2);
    }
  }

  TEST(QS8_RSUM__SSSE3_U64_ACC2, scale) {
    TEST_REQUIRES_X86_SSSE3;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(65)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u64_acc2);
    }
  }

  TEST(QS8_RSUM__SSSE3_U64_ACC2, overflow_accumulator) {
    TEST_REQUIRES_X86_SSSE3;
    RSumMicrokernelTester()
      .batch_size(8192)
      .Test(xnn_qs8_rsum_ukernel__ssse3_u64_acc2);
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(QS8_RSUM__SSSE3_U64_ACC4, batch_eq_64) {
    TEST_REQUIRES_X86_SSSE3;
    RSumMicrokernelTester()
      .batch_size(64)
      .Test(xnn_qs8_rsum_ukernel__ssse3_u64_acc4);
  }

  TEST(QS8_RSUM__SSSE3_U64_ACC4, batch_div_64) {
    TEST_REQUIRES_X86_SSSE3;
    for (size_t batch_size = 128; batch_size < 640; batch_size += 64) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u64_acc4);
    }
  }

  TEST(QS8_RSUM__SSSE3_U64_ACC4, batch_lt_64) {
    TEST_REQUIRES_X86_SSSE3;
    for (size_t batch_size = 1; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u64_acc4);
    }
  }

  TEST(QS8_RSUM__SSSE3_U64_ACC4, batch_gt_64) {
    TEST_REQUIRES_X86_SSSE3;
    for (size_t batch_size = 65; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u64_acc4);
    }
  }

  TEST(QS8_RSUM__SSSE3_U64_ACC4, scale) {
    TEST_REQUIRES_X86_SSSE3;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(65)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__ssse3_u64_acc4);
    }
  }

  TEST(QS8_RSUM__SSSE3_U64_ACC4, overflow_accumulator) {
    TEST_REQUIRES_X86_SSSE3;
    RSumMicrokernelTester()
      .batch_size(8192)
      .Test(xnn_qs8_rsum_ukernel__ssse3_u64_acc4);
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(QS8_RSUM__AVX2_U32, batch_eq_32) {
    TEST_REQUIRES_X86_AVX2;
    RSumMicrokernelTester()
      .batch_size(32)
      .Test(xnn_qs8_rsum_ukernel__avx2_u32);
  }

  TEST(QS8_RSUM__AVX2_U32, batch_div_32) {
    TEST_REQUIRES_X86_AVX2;
    for (size_t batch_size = 64; batch_size < 320; batch_size += 32) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx2_u32);
    }
  }

  TEST(QS8_RSUM__AVX2_U32, batch_lt_32) {
    TEST_REQUIRES_X86_AVX2;
    for (size_t batch_size = 1; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx2_u32);
    }
  }

  TEST(QS8_RSUM__AVX2_U32, batch_gt_32) {
    TEST_REQUIRES_X86_AVX2;
    for (size_t batch_size = 33; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx2_u32);
    }
  }

  TEST(QS8_RSUM__AVX2_U32, scale) {
    TEST_REQUIRES_X86_AVX2;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(33)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx2_u32);
    }
  }

  TEST(QS8_RSUM__AVX2_U32, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX2;
    RSumMicrokernelTester()
      .batch_size(4096)
      .Test(xnn_qs8_rsum_ukernel__avx2_u32);
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(QS8_RSUM__AVX2_U64_ACC2, batch_eq_64) {
    TEST_REQUIRES_X86_AVX2;
    RSumMicrokernelTester()
      .batch_size(64)
      .Test(xnn_qs8_rsum_ukernel__avx2_u64_acc2);
  }

  TEST(QS8_RSUM__AVX2_U64_ACC2, batch_div_64) {
    TEST_REQUIRES_X86_AVX2;
    for (size_t batch_size = 128; batch_size < 640; batch_size += 64) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx2_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVX2_U64_ACC2, batch_lt_64) {
    TEST_REQUIRES_X86_AVX2;
    for (size_t batch_size = 1; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx2_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVX2_U64_ACC2, batch_gt_64) {
    TEST_REQUIRES_X86_AVX2;
    for (size_t batch_size = 65; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx2_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVX2_U64_ACC2, scale) {
    TEST_REQUIRES_X86_AVX2;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(65)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx2_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVX2_U64_ACC2, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX2;
    RSumMicrokernelTester()
      .batch_size(8192)
      .Test(xnn_qs8_rsum_ukernel__avx2_u64_acc2);
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(QS8_RSUM__AVX2_U128_ACC2, batch_eq_128) {
    TEST_REQUIRES_X86_AVX2;
    RSumMicrokernelTester()
      .batch_size(128)
      .Test(xnn_qs8_rsum_ukernel__avx2_u128_acc2);
  }

  TEST(QS8_RSUM__AVX2_U128_ACC2, batch_div_128) {
    TEST_REQUIRES_X86_AVX2;
    for (size_t batch_size = 256; batch_size < 1280; batch_size += 128) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx2_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX2_U128_ACC2, batch_lt_128) {
    TEST_REQUIRES_X86_AVX2;
    for (size_t batch_size = 1; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx2_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX2_U128_ACC2, batch_gt_128) {
    TEST_REQUIRES_X86_AVX2;
    for (size_t batch_size = 129; batch_size < 256; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx2_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX2_U128_ACC2, scale) {
    TEST_REQUIRES_X86_AVX2;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(129)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx2_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX2_U128_ACC2, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX2;
    RSumMicrokernelTester()
      .batch_size(16384)
      .Test(xnn_qs8_rsum_ukernel__avx2_u128_acc2);
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(QS8_RSUM__AVX2_U128_ACC4, batch_eq_128) {
    TEST_REQUIRES_X86_AVX2;
    RSumMicrokernelTester()
      .batch_size(128)
      .Test(xnn_qs8_rsum_ukernel__avx2_u128_acc4);
  }

  TEST(QS8_RSUM__AVX2_U128_ACC4, batch_div_128) {
    TEST_REQUIRES_X86_AVX2;
    for (size_t batch_size = 256; batch_size < 1280; batch_size += 128) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx2_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVX2_U128_ACC4, batch_lt_128) {
    TEST_REQUIRES_X86_AVX2;
    for (size_t batch_size = 1; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx2_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVX2_U128_ACC4, batch_gt_128) {
    TEST_REQUIRES_X86_AVX2;
    for (size_t batch_size = 129; batch_size < 256; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx2_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVX2_U128_ACC4, scale) {
    TEST_REQUIRES_X86_AVX2;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(129)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx2_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVX2_U128_ACC4, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX2;
    RSumMicrokernelTester()
      .batch_size(16384)
      .Test(xnn_qs8_rsum_ukernel__avx2_u128_acc4);
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ENABLE_AVXVNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVXVNNI_U32, batch_eq_32) {
    TEST_REQUIRES_X86_AVXVNNI;
    RSumMicrokernelTester()
      .batch_size(32)
      .Test(xnn_qs8_rsum_ukernel__avxvnni_u32);
  }

  TEST(QS8_RSUM__AVXVNNI_U32, batch_div_32) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (size_t batch_size = 64; batch_size < 320; batch_size += 32) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u32);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U32, batch_lt_32) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (size_t batch_size = 1; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u32);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U32, batch_gt_32) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (size_t batch_size = 33; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u32);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U32, scale) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(33)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u32);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U32, overflow_accumulator) {
    TEST_REQUIRES_X86_AVXVNNI;
    RSumMicrokernelTester()
      .batch_size(4096)
      .Test(xnn_qs8_rsum_ukernel__avxvnni_u32);
  }
#endif  // XNN_ENABLE_AVXVNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVXVNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVXVNNI_U64_ACC2, batch_eq_64) {
    TEST_REQUIRES_X86_AVXVNNI;
    RSumMicrokernelTester()
      .batch_size(64)
      .Test(xnn_qs8_rsum_ukernel__avxvnni_u64_acc2);
  }

  TEST(QS8_RSUM__AVXVNNI_U64_ACC2, batch_div_64) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (size_t batch_size = 128; batch_size < 640; batch_size += 64) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U64_ACC2, batch_lt_64) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (size_t batch_size = 1; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U64_ACC2, batch_gt_64) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (size_t batch_size = 65; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U64_ACC2, scale) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(65)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U64_ACC2, overflow_accumulator) {
    TEST_REQUIRES_X86_AVXVNNI;
    RSumMicrokernelTester()
      .batch_size(8192)
      .Test(xnn_qs8_rsum_ukernel__avxvnni_u64_acc2);
  }
#endif  // XNN_ENABLE_AVXVNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVXVNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVXVNNI_U128_ACC2, batch_eq_128) {
    TEST_REQUIRES_X86_AVXVNNI;
    RSumMicrokernelTester()
      .batch_size(128)
      .Test(xnn_qs8_rsum_ukernel__avxvnni_u128_acc2);
  }

  TEST(QS8_RSUM__AVXVNNI_U128_ACC2, batch_div_128) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (size_t batch_size = 256; batch_size < 1280; batch_size += 128) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U128_ACC2, batch_lt_128) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (size_t batch_size = 1; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U128_ACC2, batch_gt_128) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (size_t batch_size = 129; batch_size < 256; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U128_ACC2, scale) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(129)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U128_ACC2, overflow_accumulator) {
    TEST_REQUIRES_X86_AVXVNNI;
    RSumMicrokernelTester()
      .batch_size(16384)
      .Test(xnn_qs8_rsum_ukernel__avxvnni_u128_acc2);
  }
#endif  // XNN_ENABLE_AVXVNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVXVNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVXVNNI_U128_ACC4, batch_eq_128) {
    TEST_REQUIRES_X86_AVXVNNI;
    RSumMicrokernelTester()
      .batch_size(128)
      .Test(xnn_qs8_rsum_ukernel__avxvnni_u128_acc4);
  }

  TEST(QS8_RSUM__AVXVNNI_U128_ACC4, batch_div_128) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (size_t batch_size = 256; batch_size < 1280; batch_size += 128) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U128_ACC4, batch_lt_128) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (size_t batch_size = 1; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U128_ACC4, batch_gt_128) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (size_t batch_size = 129; batch_size < 256; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U128_ACC4, scale) {
    TEST_REQUIRES_X86_AVXVNNI;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(129)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avxvnni_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVXVNNI_U128_ACC4, overflow_accumulator) {
    TEST_REQUIRES_X86_AVXVNNI;
    RSumMicrokernelTester()
      .batch_size(16384)
      .Test(xnn_qs8_rsum_ukernel__avxvnni_u128_acc4);
  }
#endif  // XNN_ENABLE_AVXVNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX256VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX256VNNI_U32, batch_eq_32) {
    TEST_REQUIRES_X86_AVX256VNNI;
    RSumMicrokernelTester()
      .batch_size(32)
      .Test(xnn_qs8_rsum_ukernel__avx256vnni_u32);
  }

  TEST(QS8_RSUM__AVX256VNNI_U32, batch_div_32) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (size_t batch_size = 64; batch_size < 320; batch_size += 32) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u32);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U32, batch_lt_32) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (size_t batch_size = 1; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u32);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U32, batch_gt_32) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (size_t batch_size = 33; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u32);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U32, scale) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(33)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u32);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U32, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX256VNNI;
    RSumMicrokernelTester()
      .batch_size(4096)
      .Test(xnn_qs8_rsum_ukernel__avx256vnni_u32);
  }
#endif  // XNN_ENABLE_AVX256VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX256VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX256VNNI_U64_ACC2, batch_eq_64) {
    TEST_REQUIRES_X86_AVX256VNNI;
    RSumMicrokernelTester()
      .batch_size(64)
      .Test(xnn_qs8_rsum_ukernel__avx256vnni_u64_acc2);
  }

  TEST(QS8_RSUM__AVX256VNNI_U64_ACC2, batch_div_64) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (size_t batch_size = 128; batch_size < 640; batch_size += 64) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U64_ACC2, batch_lt_64) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (size_t batch_size = 1; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U64_ACC2, batch_gt_64) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (size_t batch_size = 65; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U64_ACC2, scale) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(65)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U64_ACC2, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX256VNNI;
    RSumMicrokernelTester()
      .batch_size(8192)
      .Test(xnn_qs8_rsum_ukernel__avx256vnni_u64_acc2);
  }
#endif  // XNN_ENABLE_AVX256VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX256VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX256VNNI_U128_ACC2, batch_eq_128) {
    TEST_REQUIRES_X86_AVX256VNNI;
    RSumMicrokernelTester()
      .batch_size(128)
      .Test(xnn_qs8_rsum_ukernel__avx256vnni_u128_acc2);
  }

  TEST(QS8_RSUM__AVX256VNNI_U128_ACC2, batch_div_128) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (size_t batch_size = 256; batch_size < 1280; batch_size += 128) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U128_ACC2, batch_lt_128) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (size_t batch_size = 1; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U128_ACC2, batch_gt_128) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (size_t batch_size = 129; batch_size < 256; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U128_ACC2, scale) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(129)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U128_ACC2, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX256VNNI;
    RSumMicrokernelTester()
      .batch_size(16384)
      .Test(xnn_qs8_rsum_ukernel__avx256vnni_u128_acc2);
  }
#endif  // XNN_ENABLE_AVX256VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX256VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX256VNNI_U128_ACC4, batch_eq_128) {
    TEST_REQUIRES_X86_AVX256VNNI;
    RSumMicrokernelTester()
      .batch_size(128)
      .Test(xnn_qs8_rsum_ukernel__avx256vnni_u128_acc4);
  }

  TEST(QS8_RSUM__AVX256VNNI_U128_ACC4, batch_div_128) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (size_t batch_size = 256; batch_size < 1280; batch_size += 128) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U128_ACC4, batch_lt_128) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (size_t batch_size = 1; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U128_ACC4, batch_gt_128) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (size_t batch_size = 129; batch_size < 256; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U128_ACC4, scale) {
    TEST_REQUIRES_X86_AVX256VNNI;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(129)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx256vnni_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVX256VNNI_U128_ACC4, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX256VNNI;
    RSumMicrokernelTester()
      .batch_size(16384)
      .Test(xnn_qs8_rsum_ukernel__avx256vnni_u128_acc4);
  }
#endif  // XNN_ENABLE_AVX256VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX256SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX256SKX_U32, batch_eq_32) {
    TEST_REQUIRES_X86_AVX256SKX;
    RSumMicrokernelTester()
      .batch_size(32)
      .Test(xnn_qs8_rsum_ukernel__avx256skx_u32);
  }

  TEST(QS8_RSUM__AVX256SKX_U32, batch_div_32) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (size_t batch_size = 64; batch_size < 320; batch_size += 32) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u32);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U32, batch_lt_32) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (size_t batch_size = 1; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u32);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U32, batch_gt_32) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (size_t batch_size = 33; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u32);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U32, scale) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(33)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u32);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U32, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX256SKX;
    RSumMicrokernelTester()
      .batch_size(4096)
      .Test(xnn_qs8_rsum_ukernel__avx256skx_u32);
  }
#endif  // XNN_ENABLE_AVX256SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX256SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX256SKX_U64_ACC2, batch_eq_64) {
    TEST_REQUIRES_X86_AVX256SKX;
    RSumMicrokernelTester()
      .batch_size(64)
      .Test(xnn_qs8_rsum_ukernel__avx256skx_u64_acc2);
  }

  TEST(QS8_RSUM__AVX256SKX_U64_ACC2, batch_div_64) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (size_t batch_size = 128; batch_size < 640; batch_size += 64) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U64_ACC2, batch_lt_64) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (size_t batch_size = 1; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U64_ACC2, batch_gt_64) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (size_t batch_size = 65; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U64_ACC2, scale) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(65)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u64_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U64_ACC2, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX256SKX;
    RSumMicrokernelTester()
      .batch_size(8192)
      .Test(xnn_qs8_rsum_ukernel__avx256skx_u64_acc2);
  }
#endif  // XNN_ENABLE_AVX256SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX256SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX256SKX_U128_ACC2, batch_eq_128) {
    TEST_REQUIRES_X86_AVX256SKX;
    RSumMicrokernelTester()
      .batch_size(128)
      .Test(xnn_qs8_rsum_ukernel__avx256skx_u128_acc2);
  }

  TEST(QS8_RSUM__AVX256SKX_U128_ACC2, batch_div_128) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (size_t batch_size = 256; batch_size < 1280; batch_size += 128) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U128_ACC2, batch_lt_128) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (size_t batch_size = 1; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U128_ACC2, batch_gt_128) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (size_t batch_size = 129; batch_size < 256; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U128_ACC2, scale) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(129)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U128_ACC2, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX256SKX;
    RSumMicrokernelTester()
      .batch_size(16384)
      .Test(xnn_qs8_rsum_ukernel__avx256skx_u128_acc2);
  }
#endif  // XNN_ENABLE_AVX256SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX256SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX256SKX_U128_ACC4, batch_eq_128) {
    TEST_REQUIRES_X86_AVX256SKX;
    RSumMicrokernelTester()
      .batch_size(128)
      .Test(xnn_qs8_rsum_ukernel__avx256skx_u128_acc4);
  }

  TEST(QS8_RSUM__AVX256SKX_U128_ACC4, batch_div_128) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (size_t batch_size = 256; batch_size < 1280; batch_size += 128) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U128_ACC4, batch_lt_128) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (size_t batch_size = 1; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U128_ACC4, batch_gt_128) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (size_t batch_size = 129; batch_size < 256; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U128_ACC4, scale) {
    TEST_REQUIRES_X86_AVX256SKX;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(129)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx256skx_u128_acc4);
    }
  }

  TEST(QS8_RSUM__AVX256SKX_U128_ACC4, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX256SKX;
    RSumMicrokernelTester()
      .batch_size(16384)
      .Test(xnn_qs8_rsum_ukernel__avx256skx_u128_acc4);
  }
#endif  // XNN_ENABLE_AVX256SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX512SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX512SKX_U64, batch_eq_64) {
    TEST_REQUIRES_X86_AVX512SKX;
    RSumMicrokernelTester()
      .batch_size(64)
      .Test(xnn_qs8_rsum_ukernel__avx512skx_u64);
  }

  TEST(QS8_RSUM__AVX512SKX_U64, batch_div_64) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (size_t batch_size = 128; batch_size < 640; batch_size += 64) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u64);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U64, batch_lt_64) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (size_t batch_size = 1; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u64);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U64, batch_gt_64) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (size_t batch_size = 65; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u64);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U64, scale) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(65)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u64);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U64, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX512SKX;
    RSumMicrokernelTester()
      .batch_size(8192)
      .Test(xnn_qs8_rsum_ukernel__avx512skx_u64);
  }
#endif  // XNN_ENABLE_AVX512SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX512SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX512SKX_U128_ACC2, batch_eq_128) {
    TEST_REQUIRES_X86_AVX512SKX;
    RSumMicrokernelTester()
      .batch_size(128)
      .Test(xnn_qs8_rsum_ukernel__avx512skx_u128_acc2);
  }

  TEST(QS8_RSUM__AVX512SKX_U128_ACC2, batch_div_128) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (size_t batch_size = 256; batch_size < 1280; batch_size += 128) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U128_ACC2, batch_lt_128) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (size_t batch_size = 1; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U128_ACC2, batch_gt_128) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (size_t batch_size = 129; batch_size < 256; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U128_ACC2, scale) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(129)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U128_ACC2, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX512SKX;
    RSumMicrokernelTester()
      .batch_size(16384)
      .Test(xnn_qs8_rsum_ukernel__avx512skx_u128_acc2);
  }
#endif  // XNN_ENABLE_AVX512SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX512SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX512SKX_U256_ACC2, batch_eq_256) {
    TEST_REQUIRES_X86_AVX512SKX;
    RSumMicrokernelTester()
      .batch_size(256)
      .Test(xnn_qs8_rsum_ukernel__avx512skx_u256_acc2);
  }

  TEST(QS8_RSUM__AVX512SKX_U256_ACC2, batch_div_256) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (size_t batch_size = 512; batch_size < 2560; batch_size += 256) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u256_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U256_ACC2, batch_lt_256) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (size_t batch_size = 1; batch_size < 256; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u256_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U256_ACC2, batch_gt_256) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (size_t batch_size = 257; batch_size < 512; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u256_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U256_ACC2, scale) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(257)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u256_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U256_ACC2, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX512SKX;
    RSumMicrokernelTester()
      .batch_size(32768)
      .Test(xnn_qs8_rsum_ukernel__avx512skx_u256_acc2);
  }
#endif  // XNN_ENABLE_AVX512SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX512SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX512SKX_U256_ACC4, batch_eq_256) {
    TEST_REQUIRES_X86_AVX512SKX;
    RSumMicrokernelTester()
      .batch_size(256)
      .Test(xnn_qs8_rsum_ukernel__avx512skx_u256_acc4);
  }

  TEST(QS8_RSUM__AVX512SKX_U256_ACC4, batch_div_256) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (size_t batch_size = 512; batch_size < 2560; batch_size += 256) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u256_acc4);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U256_ACC4, batch_lt_256) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (size_t batch_size = 1; batch_size < 256; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u256_acc4);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U256_ACC4, batch_gt_256) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (size_t batch_size = 257; batch_size < 512; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u256_acc4);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U256_ACC4, scale) {
    TEST_REQUIRES_X86_AVX512SKX;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(257)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx512skx_u256_acc4);
    }
  }

  TEST(QS8_RSUM__AVX512SKX_U256_ACC4, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX512SKX;
    RSumMicrokernelTester()
      .batch_size(32768)
      .Test(xnn_qs8_rsum_ukernel__avx512skx_u256_acc4);
  }
#endif  // XNN_ENABLE_AVX512SKX && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX512VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX512VNNI_U64, batch_eq_64) {
    TEST_REQUIRES_X86_AVX512VNNI;
    RSumMicrokernelTester()
      .batch_size(64)
      .Test(xnn_qs8_rsum_ukernel__avx512vnni_u64);
  }

  TEST(QS8_RSUM__AVX512VNNI_U64, batch_div_64) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (size_t batch_size = 128; batch_size < 640; batch_size += 64) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u64);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U64, batch_lt_64) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (size_t batch_size = 1; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u64);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U64, batch_gt_64) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (size_t batch_size = 65; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u64);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U64, scale) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(65)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u64);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U64, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX512VNNI;
    RSumMicrokernelTester()
      .batch_size(8192)
      .Test(xnn_qs8_rsum_ukernel__avx512vnni_u64);
  }
#endif  // XNN_ENABLE_AVX512VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX512VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX512VNNI_U128_ACC2, batch_eq_128) {
    TEST_REQUIRES_X86_AVX512VNNI;
    RSumMicrokernelTester()
      .batch_size(128)
      .Test(xnn_qs8_rsum_ukernel__avx512vnni_u128_acc2);
  }

  TEST(QS8_RSUM__AVX512VNNI_U128_ACC2, batch_div_128) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (size_t batch_size = 256; batch_size < 1280; batch_size += 128) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U128_ACC2, batch_lt_128) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (size_t batch_size = 1; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U128_ACC2, batch_gt_128) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (size_t batch_size = 129; batch_size < 256; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U128_ACC2, scale) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(129)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u128_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U128_ACC2, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX512VNNI;
    RSumMicrokernelTester()
      .batch_size(16384)
      .Test(xnn_qs8_rsum_ukernel__avx512vnni_u128_acc2);
  }
#endif  // XNN_ENABLE_AVX512VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX512VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX512VNNI_U256_ACC2, batch_eq_256) {
    TEST_REQUIRES_X86_AVX512VNNI;
    RSumMicrokernelTester()
      .batch_size(256)
      .Test(xnn_qs8_rsum_ukernel__avx512vnni_u256_acc2);
  }

  TEST(QS8_RSUM__AVX512VNNI_U256_ACC2, batch_div_256) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (size_t batch_size = 512; batch_size < 2560; batch_size += 256) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u256_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U256_ACC2, batch_lt_256) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (size_t batch_size = 1; batch_size < 256; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u256_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U256_ACC2, batch_gt_256) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (size_t batch_size = 257; batch_size < 512; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u256_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U256_ACC2, scale) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(257)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u256_acc2);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U256_ACC2, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX512VNNI;
    RSumMicrokernelTester()
      .batch_size(32768)
      .Test(xnn_qs8_rsum_ukernel__avx512vnni_u256_acc2);
  }
#endif  // XNN_ENABLE_AVX512VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX512VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(QS8_RSUM__AVX512VNNI_U256_ACC4, batch_eq_256) {
    TEST_REQUIRES_X86_AVX512VNNI;
    RSumMicrokernelTester()
      .batch_size(256)
      .Test(xnn_qs8_rsum_ukernel__avx512vnni_u256_acc4);
  }

  TEST(QS8_RSUM__AVX512VNNI_U256_ACC4, batch_div_256) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (size_t batch_size = 512; batch_size < 2560; batch_size += 256) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u256_acc4);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U256_ACC4, batch_lt_256) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (size_t batch_size = 1; batch_size < 256; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u256_acc4);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U256_ACC4, batch_gt_256) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (size_t batch_size = 257; batch_size < 512; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u256_acc4);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U256_ACC4, scale) {
    TEST_REQUIRES_X86_AVX512VNNI;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(257)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__avx512vnni_u256_acc4);
    }
  }

  TEST(QS8_RSUM__AVX512VNNI_U256_ACC4, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX512VNNI;
    RSumMicrokernelTester()
      .batch_size(32768)
      .Test(xnn_qs8_rsum_ukernel__avx512vnni_u256_acc4);
  }
#endif  // XNN_ENABLE_AVX512VNNI && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ARCH_WASMRELAXEDSIMD
  TEST(QS8_RSUM__WASMRELAXEDSIMD_U16, batch_eq_16) {
    RSumMicrokernelTester()
      .batch_size(16)
      .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u16);
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U16, batch_div_16) {
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u16);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U16, batch_lt_16) {
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u16);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U16, batch_gt_16) {
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u16);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U16, scale) {
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(17)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u16);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U16, overflow_accumulator) {
    RSumMicrokernelTester()
      .batch_size(2048)
      .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u16);
  }
#endif  // XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMRELAXEDSIMD
  TEST(QS8_RSUM__WASMRELAXEDSIMD_U32_ACC2, batch_eq_32) {
    RSumMicrokernelTester()
      .batch_size(32)
      .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u32_acc2);
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U32_ACC2, batch_div_32) {
    for (size_t batch_size = 64; batch_size < 320; batch_size += 32) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u32_acc2);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U32_ACC2, batch_lt_32) {
    for (size_t batch_size = 1; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u32_acc2);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U32_ACC2, batch_gt_32) {
    for (size_t batch_size = 33; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u32_acc2);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U32_ACC2, scale) {
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(33)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u32_acc2);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U32_ACC2, overflow_accumulator) {
    RSumMicrokernelTester()
      .batch_size(4096)
      .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u32_acc2);
  }
#endif  // XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMRELAXEDSIMD
  TEST(QS8_RSUM__WASMRELAXEDSIMD_U64_ACC2, batch_eq_64) {
    RSumMicrokernelTester()
      .batch_size(64)
      .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u64_acc2);
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U64_ACC2, batch_div_64) {
    for (size_t batch_size = 128; batch_size < 640; batch_size += 64) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u64_acc2);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U64_ACC2, batch_lt_64) {
    for (size_t batch_size = 1; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u64_acc2);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U64_ACC2, batch_gt_64) {
    for (size_t batch_size = 65; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u64_acc2);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U64_ACC2, scale) {
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(65)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u64_acc2);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U64_ACC2, overflow_accumulator) {
    RSumMicrokernelTester()
      .batch_size(8192)
      .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u64_acc2);
  }
#endif  // XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMRELAXEDSIMD
  TEST(QS8_RSUM__WASMRELAXEDSIMD_U64_ACC4, batch_eq_64) {
    RSumMicrokernelTester()
      .batch_size(64)
      .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u64_acc4);
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U64_ACC4, batch_div_64) {
    for (size_t batch_size = 128; batch_size < 640; batch_size += 64) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u64_acc4);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U64_ACC4, batch_lt_64) {
    for (size_t batch_size = 1; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u64_acc4);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U64_ACC4, batch_gt_64) {
    for (size_t batch_size = 65; batch_size < 128; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u64_acc4);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U64_ACC4, scale) {
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(65)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u64_acc4);
    }
  }

  TEST(QS8_RSUM__WASMRELAXEDSIMD_U64_ACC4, overflow_accumulator) {
    RSumMicrokernelTester()
      .batch_size(8192)
      .Test(xnn_qs8_rsum_ukernel__wasmrelaxedsimd_u64_acc4);
  }
#endif  // XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(QS8_RSUM__WASMSIMD_U8, batch_eq_8) {
    RSumMicrokernelTester()
      .batch_size(8)
      .Test(xnn_qs8_rsum_ukernel__wasmsimd_u8);
  }

  TEST(QS8_RSUM__WASMSIMD_U8, batch_div_8) {
    for (size_t batch_size = 16; batch_size < 80; batch_size += 8) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u8);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U8, batch_lt_8) {
    for (size_t batch_size = 1; batch_size < 8; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u8);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U8, batch_gt_8) {
    for (size_t batch_size = 9; batch_size < 16; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u8);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U8, scale) {
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(9)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u8);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U8, overflow_accumulator) {
    RSumMicrokernelTester()
      .batch_size(1024)
      .Test(xnn_qs8_rsum_ukernel__wasmsimd_u8);
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(QS8_RSUM__WASMSIMD_U16_ACC2, batch_eq_16) {
    RSumMicrokernelTester()
      .batch_size(16)
      .Test(xnn_qs8_rsum_ukernel__wasmsimd_u16_acc2);
  }

  TEST(QS8_RSUM__WASMSIMD_U16_ACC2, batch_div_16) {
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u16_acc2);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U16_ACC2, batch_lt_16) {
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u16_acc2);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U16_ACC2, batch_gt_16) {
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u16_acc2);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U16_ACC2, scale) {
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(17)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u16_acc2);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U16_ACC2, overflow_accumulator) {
    RSumMicrokernelTester()
      .batch_size(2048)
      .Test(xnn_qs8_rsum_ukernel__wasmsimd_u16_acc2);
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(QS8_RSUM__WASMSIMD_U32_ACC2, batch_eq_32) {
    RSumMicrokernelTester()
      .batch_size(32)
      .Test(xnn_qs8_rsum_ukernel__wasmsimd_u32_acc2);
  }

  TEST(QS8_RSUM__WASMSIMD_U32_ACC2, batch_div_32) {
    for (size_t batch_size = 64; batch_size < 320; batch_size += 32) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u32_acc2);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U32_ACC2, batch_lt_32) {
    for (size_t batch_size = 1; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u32_acc2);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U32_ACC2, batch_gt_32) {
    for (size_t batch_size = 33; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u32_acc2);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U32_ACC2, scale) {
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(33)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u32_acc2);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U32_ACC2, overflow_accumulator) {
    RSumMicrokernelTester()
      .batch_size(4096)
      .Test(xnn_qs8_rsum_ukernel__wasmsimd_u32_acc2);
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(QS8_RSUM__WASMSIMD_U32_ACC4, batch_eq_32) {
    RSumMicrokernelTester()
      .batch_size(32)
      .Test(xnn_qs8_rsum_ukernel__wasmsimd_u32_acc4);
  }

  TEST(QS8_RSUM__WASMSIMD_U32_ACC4, batch_div_32) {
    for (size_t batch_size = 64; batch_size < 320; batch_size += 32) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u32_acc4);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U32_ACC4, batch_lt_32) {
    for (size_t batch_size = 1; batch_size < 32; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u32_acc4);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U32_ACC4, batch_gt_32) {
    for (size_t batch_size = 33; batch_size < 64; batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u32_acc4);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U32_ACC4, scale) {
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(33)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__wasmsimd_u32_acc4);
    }
  }

  TEST(QS8_RSUM__WASMSIMD_U32_ACC4, overflow_accumulator) {
    RSumMicrokernelTester()
      .batch_size(4096)
      .Test(xnn_qs8_rsum_ukernel__wasmsimd_u32_acc4);
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ENABLE_RISCV_VECTOR && XNN_ARCH_RISCV
  TEST(QS8_RSUM__RVV_U1V, batch_eq_1v) {
    TEST_REQUIRES_RISCV_VECTOR;
    RSumMicrokernelTester()
      .batch_size(1 * xnn_init_hardware_config()->vlenb / sizeof(int8_t))
      .Test(xnn_qs8_rsum_ukernel__rvv_u1v);
  }

  TEST(QS8_RSUM__RVV_U1V, batch_div_1v) {
    TEST_REQUIRES_RISCV_VECTOR;
    for (size_t batch_size = 2 * xnn_init_hardware_config()->vlenb / sizeof(int8_t);
                batch_size < 10 * xnn_init_hardware_config()->vlenb / sizeof(int8_t);
                batch_size += 1 * xnn_init_hardware_config()->vlenb / sizeof(int8_t)) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__rvv_u1v);
    }
  }

  TEST(QS8_RSUM__RVV_U1V, batch_lt_1v) {
    TEST_REQUIRES_RISCV_VECTOR;
    for (size_t batch_size = 1;
                batch_size < 1 * xnn_init_hardware_config()->vlenb / sizeof(int8_t);
                batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__rvv_u1v);
    }
  }

  TEST(QS8_RSUM__RVV_U1V, batch_gt_1v) {
    TEST_REQUIRES_RISCV_VECTOR;
    for (size_t batch_size = 1 * xnn_init_hardware_config()->vlenb / sizeof(int8_t) + 1;
                batch_size < 10 * xnn_init_hardware_config()->vlenb / sizeof(int8_t);
                batch_size += 2) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__rvv_u1v);
    }
  }

  TEST(QS8_RSUM__RVV_U1V, scale) {
    TEST_REQUIRES_RISCV_VECTOR;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(1 * xnn_init_hardware_config()->vlenb / sizeof(int8_t) + 1)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__rvv_u1v);
    }
  }

  TEST(QS8_RSUM__RVV_U1V, overflow_accumulator) {
    TEST_REQUIRES_RISCV_VECTOR;
    RSumMicrokernelTester()
      .batch_size(128)
      .Test(xnn_qs8_rsum_ukernel__rvv_u1v);
  }
#endif  // XNN_ENABLE_RISCV_VECTOR && XNN_ARCH_RISCV


#if XNN_ENABLE_RISCV_VECTOR && XNN_ARCH_RISCV
  TEST(QS8_RSUM__RVV_U2V, batch_eq_2v) {
    TEST_REQUIRES_RISCV_VECTOR;
    RSumMicrokernelTester()
      .batch_size(2 * xnn_init_hardware_config()->vlenb / sizeof(int8_t))
      .Test(xnn_qs8_rsum_ukernel__rvv_u2v);
  }

  TEST(QS8_RSUM__RVV_U2V, batch_div_2v) {
    TEST_REQUIRES_RISCV_VECTOR;
    for (size_t batch_size = 4 * xnn_init_hardware_config()->vlenb / sizeof(int8_t);
                batch_size < 20 * xnn_init_hardware_config()->vlenb / sizeof(int8_t);
                batch_size += 2 * xnn_init_hardware_config()->vlenb / sizeof(int8_t)) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__rvv_u2v);
    }
  }

  TEST(QS8_RSUM__RVV_U2V, batch_lt_2v) {
    TEST_REQUIRES_RISCV_VECTOR;
    for (size_t batch_size = 1;
                batch_size < 2 * xnn_init_hardware_config()->vlenb / sizeof(int8_t);
                batch_size++) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__rvv_u2v);
    }
  }

  TEST(QS8_RSUM__RVV_U2V, batch_gt_2v) {
    TEST_REQUIRES_RISCV_VECTOR;
    for (size_t batch_size = 2 * xnn_init_hardware_config()->vlenb / sizeof(int8_t) + 1;
                batch_size < 4 * xnn_init_hardware_config()->vlenb / sizeof(int8_t);
                batch_size += 4) {
      RSumMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_qs8_rsum_ukernel__rvv_u2v);
    }
  }

  TEST(QS8_RSUM__RVV_U2V, scale) {
    TEST_REQUIRES_RISCV_VECTOR;
    for (float scale = 0.3f; scale < 5.0f; scale *= 3.0f) {
      RSumMicrokernelTester()
        .batch_size(2 * xnn_init_hardware_config()->vlenb / sizeof(int8_t) + 1)
        .scale(scale)
        .Test(xnn_qs8_rsum_ukernel__rvv_u2v);
    }
  }

  TEST(QS8_RSUM__RVV_U2V, overflow_accumulator) {
    TEST_REQUIRES_RISCV_VECTOR;
    RSumMicrokernelTester()
      .batch_size(256)
      .Test(xnn_qs8_rsum_ukernel__rvv_u2v);
  }
#endif  // XNN_ENABLE_RISCV_VECTOR && XNN_ARCH_RISCV
