/*
 * Copyright (c) 2021-2022 Amlogic, Inc. All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef __SOC_H
#define __SOC_H
#ifndef __ASM
#include "FreeRTOSConfig.h"
#include "riscv_const.h"
#include "irq.h"
#include "register.h"
#endif

#define SOC_ECLIC_NUM_INTERRUPTS 32
#define SOC_TIMER_FREQ           configCPU_CLOCK_HZ
#define SOC_ECLIC_CTRL_ADDR      0x0C000000UL
#define SOC_TIMER_CTRL_ADDR      0x02000000UL
#define SOC_PMP_BASE             0xff100000UL
#define SOC_LOCAL_SRAM_BASE      0x10000000UL
#define SRAM_BEGIN               SOC_LOCAL_SRAM_BASE
#define SRAM_SIZE                (0x20000)//(96*1024)
#define SRAM_END                 (SRAM_BEGIN + SRAM_SIZE)
#define IO_BASE                  0xff000000UL
#define IO_SIZE                  0x00100000
#define IO_BEGIN                 (IO_BASE)
#define IO_END                   (IO_BASE + IO_SIZE)

/*SoC/Shadow register mapping*/
#define VRTC_PARA_REG SYSCTRL_STATUS_REG2
#define VRTC_STICKY_REG SYSCTRL_STICKY_REG2

#define TIMERE_LOW_REG SYSCTRL_TIMERE
#define TIMERE_HIG_REG SYSCTRL_TIMERE_HI
#define WAKEUP_REASON_STICK_REG SYSCTRL_STICKY_REG7
#define FSM_TRIGER_CTRL SYSCTRL_TIMERB_CTRL
#define FSM_TRIGER_SRC SYSCTRL_TIMERB

#define TIMER_CLK_SEL_SYS_CLK 0
#define TIMER_CLK_SEL_1US 1
#define TIMER_CLK_SEL_10US 2
#define TIMER_CLK_SEL_100US 3
#define TIMER_MODE_IRQ_PERIO (1 << 6)
#define TIMER_EN (1 << 7)

#define UART_PORT_CONS UART_B_WFIFO
#define UART_PORT_WAKEUP_IRQ IRQ_NUM_AO_UART_C
#define UART_PORT_WAKEUP_REG_BASE UART_AO_WFIFO

#define SYSCTRL_TIMER SYSCTRL_TIMERJ
#define SYSTICK_TIMER_CTRL SYSCTRL_TIMERJ_CTRL
#define SYSTICK_TIMER_CTRL_PARM	(TIMER_MODE_IRQ_PERIO | TIMER_EN | TIMER_CLK_SEL_1US)
#define DSP_FSM_TRIGER_CTRL SYSCTRL_TIMERI_CTRL
#define DSP_FSM_TRIGER_SRC SYSCTRL_TIMERI

#endif
