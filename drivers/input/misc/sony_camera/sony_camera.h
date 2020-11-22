/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */
/*
 * Copyright (C) 2019 Sony Mobile Communications Inc.
 */

#ifndef __LINUX_SONY_CAMERA_H
#define __LINUX_SONY_CAMERA_H

#include <linux/time.h>

#define SONY_CAMERA_MAX_I2C_DATA       (256)
#define SONY_CAMERA_MAX_EEPROM_DATA    (8192)

#define SONY_CAMERA_CMD_BASE              (0x10000)
#define SONY_CAMERA_CMD_POWER_UP          (SONY_CAMERA_CMD_BASE + 0)
#define SONY_CAMERA_CMD_POWER_DOWN        (SONY_CAMERA_CMD_BASE + 1)
#define SONY_CAMERA_CMD_I2C_READ          (SONY_CAMERA_CMD_BASE + 2)
#define SONY_CAMERA_CMD_I2C_WRITE         (SONY_CAMERA_CMD_BASE + 3)
#define SONY_CAMERA_CMD_GET_EVENT         (SONY_CAMERA_CMD_BASE + 4)
#define SONY_CAMERA_CMD_SET_THERMAL       (SONY_CAMERA_CMD_BASE + 5)
#define SONY_CAMERA_CMD_CLEAR             (SONY_CAMERA_CMD_BASE + 6)
#define SONY_CAMERA_CMD_BUG_ON            (SONY_CAMERA_CMD_BASE + 7)
#define SONY_CAMERA_CMD_GET_POWER_STATE   (SONY_CAMERA_CMD_BASE + 8)
#define SONY_CAMERA_CMD_GET_I2C_FREQ_MODE (SONY_CAMERA_CMD_BASE + 9)
#define SONY_CAMERA_CMD_SET_I2C_FREQ_MODE (SONY_CAMERA_CMD_BASE + 10)

#define SONY_CAMERA_EVT_BASE           (0x20000)
#define SONY_CAMERA_EVT_SOF            (SONY_CAMERA_EVT_BASE + 0)

enum sony_camera_i2c_freq_mode {
	SONY_CAMERA_I2C_FREQ_MODE_STAND,
	SONY_CAMERA_I2C_FREQ_MODE_FAST,
	SONY_CAMERA_I2C_FREQ_MODE_CUSTOM,
	SONY_CAMERA_I2C_FREQ_MODE_FAST_PLUS,
	SONY_CAMERA_I2C_FREQ_MODE_MAX,
};

enum sony_camera_i2c_type {
	SONY_CAMERA_I2C_TYPE_INVALID,
	SONY_CAMERA_I2C_TYPE_BYTE,
	SONY_CAMERA_I2C_TYPE_WORD,
	SONY_CAMERA_I2C_TYPE_3B,
	SONY_CAMERA_I2C_TYPE_MAX,
};

struct sony_camera_i2c_data {
	uint32_t	slave_addr;
	uint32_t	addr;
	uint32_t	addr_type;
	uint32_t	len;
	uint8_t		data[SONY_CAMERA_MAX_I2C_DATA];
};

struct sony_camera_eeprom_data {
	uint8_t		data[SONY_CAMERA_MAX_EEPROM_DATA];
};

struct sony_camera_event_sof_data {
	uint32_t	sof_count;
	struct		timeval mono_timestamp;
};

struct sony_camera_event_data {
	uint32_t	type;
	struct	sony_camera_event_sof_data sof_data;
};

struct sony_camera_thermal_data {
	int32_t		temperature;
};

#endif /* __LINUX_SONY_CAMERA_H */
