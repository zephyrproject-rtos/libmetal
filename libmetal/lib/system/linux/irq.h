/*
 * Copyright (c) 2016, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file	linux/irq.h
 * @brief	Linux libmetal irq definitions.
 */

#ifndef __METAL_IRQ__H__
#error "Do not include this file directly, include <metal/irq.h> instead"
#endif

#ifndef __METAL_LINUX_IRQ__H__
#ifdef METAL_INTERNAL

#include <metal/device.h>

/**
 * @brief	metal_linux_register_dev
 *
 * Metal Linux internal function to register metal device to a IRQ
 * which is generated from the device.
 *
 * @param[in]	dev pointer to metal device
 * @param[in]	irq interrupt id
 */
void metal_linux_irq_register_dev(struct metal_device *dev, int irq);

/**
 * @brief	Unregister the metal device associated with a Linux IRQ.
 *
 * Metal Linux internal function to clear device bookkeeping for an IRQ. The
 * IRQ consumer must disable the IRQ before unregistering the device.
 *
 * @param[in]	irq interrupt id
 * @return	0 on success, or -errno on error.
 */
int metal_linux_irq_unregister_dev(int irq);

/**
 * @brief	Get the metal device associated with a Linux IRQ.
 *
 * @param[in]	irq interrupt id
 * @return	Registered metal device, or NULL if none is registered.
 */
struct metal_device *metal_linux_irq_get_dev(int irq);

/**
 * @brief	Check whether a Linux IRQ is enabled.
 *
 * @param[in]	irq interrupt id
 * @return	1 if the IRQ is enabled, or 0 otherwise.
 */
int metal_linux_irq_is_enabled(int irq);

#endif /* METAL_INTERNAL */
#define __METAL_LINUX_IRQ__H__

#endif /* __METAL_LINUX_IRQ__H__ */
