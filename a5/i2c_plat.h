/*
 * Copyright (c) 2021-2022 Amlogic, Inc. All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * platform related header file
 */
#ifndef _MESON_I2C_PLAT_H_
#define _MESON_I2C_PLAT_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "FreeRTOS.h"
#include <common.h>
#include <meson_i2c.h>

#define CLKCTRL_SYS_CLK_EN0_REG0                   ((0x0011  << 2) + 0xfe000000)
#define CLKCTRL_SYS_CLK_EN0_REG1                   ((0x0012  << 2) + 0xfe000000)
#define CLKCTRL_SYS_CLK_EN0_REG2                   ((0x0013  << 2) + 0xfe000000)
#define CLKCTRL_SYS_CLK_EN0_REG3                   ((0x0014  << 2) + 0xfe000000)

struct xMesonI2cPlatdata i2c_plat_data[] = {
	{ 0, 0xfe066000, 3, 15, 100000, MESON_I2C_CLK_RATE,
						CLKCTRL_SYS_CLK_EN0_REG1, 16 }, /* i2c A */
	{ 1, 0xfe068000, 3, 15, 100000, MESON_I2C_CLK_RATE,
						CLKCTRL_SYS_CLK_EN0_REG1, 17 }, /* i2c B */
	{ 2, 0xfe06a000, 3, 15, 100000, MESON_I2C_CLK_RATE,
						CLKCTRL_SYS_CLK_EN0_REG1, 18 }, /* i2c C */
	{ 3, 0xfe06c000, 3, 15, 100000, MESON_I2C_CLK_RATE,
						CLKCTRL_SYS_CLK_EN0_REG1, 19 }, /* i2c D */
};

#ifdef __cplusplus
}
#endif
#endif /* _MESON_I2C_PLAT_H_ */
