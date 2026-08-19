#
# Copyright (c) 2018 Linaro Limited
#
# SPDX-License-Identifier: Apache-2.0
#

if(CONFIG_LIBMETAL)
set(WITH_ZEPHYR 1)
set(WITH_ZEPHYR_LIB 1)
set(WITH_DOC OFF CACHE BOOL "" FORCE)
set(WITH_DEFAULT_LOGGER OFF CACHE BOOL "" FORCE)

if(CONFIG_ARCH_POSIX)
	# When building Zephyr for the POSIX architecture,
	# we need to set CMAKE_SYSTEM_PROCESSOR to "hosted" which is
	# what the libmetal build expects for such a target.
	set(CMAKE_SYSTEM_PROCESSOR "hosted")
endif()

add_subdirectory(${CONFIG_LIBMETAL_SRC_PATH} libmetal)
endif()
