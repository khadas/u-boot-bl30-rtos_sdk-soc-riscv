/*
 * Copyright (c) 2021-2022 Amlogic, Inc. All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef __MAILBOX_H__
#define __MAILBOX_H__

#include "register.h"

#define MHU_MAX_SIZE		(0x20 * 4) /*128 char*/

#define MHU_TASKID_SIZE		0x8
#define MHU_COPETE_SIZE		0x8
#define MHU_ULLCTL_SIZE		0x8
#define MHU_STS_SIZE		0x4
#define MHU_HEAD_SIZE		0x1c /*include status 0x4 task id 0x8, completion 0x8*/
#define MHU_RESEV_SIZE		0x4 /*include status 0x2 task id 0x8, completion 0x8*/
#define MHU_DATA_SIZE		(MHU_MAX_SIZE - MHU_HEAD_SIZE - MHU_RESEV_SIZE)
#define MHU_DATA_OFFSET		(MHU_HEAD_SIZE / 4) /*include status 0x4 task id 0x8, completion 0x8*/

#define IRQ_MAX			32
#define MBOX_AO_IRQ		249 //MBOX_IRQ1

#define MAILBOX_ARMREE2AO	0x3		/*mailbox1*/
#define MAILBOX_AO2ARMREE	0x2		/*mailbox1*/

#define MAILBOX_ARMTEE2AO	0x5		/*mailbox1*/
#define MAILBOX_AO2ARMTEE	0x4		/*mailbox1*/

#define MAILBOX_AOCPU_IRQ	249
#define MAILBOX_IRQ_MASK	MAILBOX_IRQB_MASK
#define MAILBOX_IRQ_CLR		MAILBOX_IRQB_CLR
#define MAILBOX_IRQ_STS		MAILBOX_IRQB_STS

#define IRQ_REV_BIT(mbox)	(1 << ((mbox) * 2))
#define IRQ_SENDACK_BIT(mbox)	(1 << ((mbox) * 2 + 1))

#define IRQ_REV_NUM(mbox)	((mbox) * 2)
#define IRQ_SENDACK_NUM(mbox)	((mbox) * 2 + 1)

#define IRQ_MASK		(IRQ_REV_BIT(MAILBOX_ARMREE2AO) | IRQ_REV_BIT(MAILBOX_ARMTEE2AO))


#define MAILBOX_STAT(MBOX)	(MAILBOX_STS_MBOX00 + 0x4 * (MBOX))  /*mailbox4 rev*/
#define MAILBOX_CLR(MBOX)	(MAILBOX_CLR_MBOX00 + 0x4 * (MBOX)) /*mailbox4 rev*/
#define MAILBOX_SET(MBOX)	(MAILBOX_SET_MBOX00 + 0x4 * (MBOX)) /*mailbox4 send*/

#define PAYLOAD_WRBASE		MAILBOX_WR_MBOX00
#define PAYLOAD_RDBASE		MAILBOX_RD_MBOX00

#define PAYLOAD_WR_BASE(MBOX)	PAYLOAD_WRBASE + (0x80 * (MBOX)) /*WR*/
#define PAYLOAD_RD_BASE(MBOX)	PAYLOAD_RDBASE + (0x80 * (MBOX)) /*RD*/

typedef void (*vHandlerFunc)(void *);

typedef struct xHandlerTableEntry {
    void (*vHandler)(void *vArg);
    void * vArg;
    unsigned int xPriority;
} xHandlerTableEntry;
#endif
