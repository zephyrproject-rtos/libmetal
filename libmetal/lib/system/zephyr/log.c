/*
 * Copyright (c) 2018, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file	zephyr/log.c
 * @brief	Zephyr libmetal log handler.
 */

#include <stdarg.h>
#include <metal/log.h>
#include <zephyr.h>

#if defined(CONFIG_LOG)
#include <logging/log.h>
LOG_MODULE_REGISTER(metal);
#endif

static uint8_t metal_to_zephyr_log_level[] = {
	LOG_LEVEL_ERR,		/* METAL_LOG_EMERGENCY */
	LOG_LEVEL_ERR,		/* METAL_LOG_ALERT */
	LOG_LEVEL_ERR,		/* METAL_LOG_CRITICAL */
	LOG_LEVEL_ERR,		/* METAL_LOG_ERROR */
	LOG_LEVEL_WRN,		/* METAL_LOG_WARNING */
	LOG_LEVEL_INF,		/* METAL_LOG_NOTICE */
	LOG_LEVEL_INF,		/* METAL_LOG_INFO, */
	LOG_LEVEL_DBG		/* METAL_LOG_DEBUG */
};

void metal_zephyr_log_handler(enum metal_log_level level,
			      const char *format, ...)
{
	va_list args;
	struct log_msg_ids src_level = {
		.level = metal_to_zephyr_log_level[level],
		.domain_id = CONFIG_LOG_DOMAIN_ID,
		.source_id = LOG_CURRENT_MODULE_ID()
	};

	if (level <= METAL_LOG_EMERGENCY || level > METAL_LOG_DEBUG) {
		level = METAL_LOG_EMERGENCY;
	}

	va_start(args, format);

#if defined(CONFIG_LOG)
	log_generic(src_level, format, args);
#endif

	va_end(args);
}

