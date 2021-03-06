/**
 ******************************************************************************
 *
 * @file       pios_servp_config.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2013.
 * @brief      Architecture specific macros and definitions
 *             --
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef PIOS_SERVO_CONFIG_H_
#define PIOS_SERVO_CONFIG_H_

/**
 * Generic servo pin configuration structure for an STM32F4xx
 */
#define TIM_SERVO_CHANNEL_CONFIG(_timer, _channel, _gpio, _pin) \
    {                                                     \
        .timer = _timer,                                  \
        .timer_chan = TIM_Channel_##_channel,             \
        .pin   = {                                        \
            .gpio = GPIO##_gpio,                          \
            .init = {                                     \
                .GPIO_Pin   = GPIO_Pin_##_pin,            \
                .GPIO_Speed = GPIO_Speed_2MHz,            \
                .GPIO_Mode  = GPIO_Mode_AF,               \
                .GPIO_OType = GPIO_OType_PP,              \
                .GPIO_PuPd  = GPIO_PuPd_UP                \
            },                                            \
            .pin_source     = GPIO_PinSource##_pin,       \
        },                                                \
        .remap = GPIO_AF_##_timer,                        \
    }


#endif /* PIOS_SERVO_CONFIG_H_ */
