/*
 * Copyright (c) 2021-2022 Amlogic, Inc. All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef _RISCV_BITS_H
#define _RISCV_BITS_H

#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

#define ROUNDUP(a, b) ((((a)-1) / (b) + 1) * (b))
#define ROUNDDOWN(a, b) ((a) / (b) * (b))

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define CLAMP(a, lo, hi) MIN(MAX(a, lo), hi)

#define EXTRACT_FIELD(val, which) (((val) & (which)) / ((which) & ~((which)-1)))
#define INSERT_FIELD(val, which, fieldval)                                                         \
	(((val) & ~(which)) | ((fieldval) * ((which) & ~((which)-1))))

#define STR(x) XSTR(x)
#define XSTR(x) #x

#if __riscv_xlen == 64
#define SLL32 sllw
#define STORE sd
#define LOAD ld
#define LWU lwu
#define LOG_REGBYTES 3
#else
#define SLL32 sll
#define STORE sw
#define LOAD lw
#define LWU lw
#define LOG_REGBYTES 2
#endif
#define REGBYTES (1 << LOG_REGBYTES)

#if __riscv_flen == 64
#define FPSTORE fsd
#define FPLOAD fld
#define LOG_FPREGBYTES 3
#else
#define FPSTORE fsw
#define FPLOAD flw
#define LOG_FPREGBYTES 2
#endif
#define FPREGBYTES (1 << LOG_FPREGBYTES)

#endif
