/*
 * Copyright (c) 2021-2022 Amlogic, Inc. All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * platform related header file
 */

#ifndef _MESON_PWM_PLAT_H_
#define _MESON_PWM_PLAT_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <register.h>

#define PwmMesonVolt_Duty 1

/* There are 4 pwm controllers in a5 */
enum pwm_chip_id {
	PWM_AB = 0,
	PWM_CD,
	PWM_EF,
	PWM_GH,
	PWM_IJ,
	PWM_MUX,
};

/* VDDEE VDDCPU in s4 */
enum pwm_voltage_id {
	VDDEE_VOLT = 0,
	VDDCPU_VOLT,
};

struct xPwmMesonVoltage {
	uint32_t Voltage_mv;
	uint32_t Duty_reg;
};

struct xPwmMesonChip {
	uint32_t chip_id;
	unsigned long addr;
	uint32_t mask;
	/*transfers the clk div, clk gate, and clk mux to the clktree.*/
	unsigned long clk_addr;
};

uint32_t prvMesonVoltToPwmchip(enum pwm_voltage_id voltage_id);
uint32_t prvMesonVoltToPwmchannel(enum pwm_voltage_id voltage_id);
struct xPwmMesonVoltage *vPwmMesonGetVoltTable(uint32_t voltage_id);
uint32_t vPwmMesonGetVoltTableSize(uint32_t voltage_id);
struct xPwmMesonChip *prvIdToPwmChip(uint32_t chip_id);

#ifdef __cplusplus
}
#endif
#endif /* _MESON_PWM_PLAT_H_ */