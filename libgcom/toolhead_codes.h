/*
 toolhead_codes.h

 This file defines the codes that the Gen3 extruder controller understands.
     
 Part of the gcom project
 Copyright (c) 2011 Jestin Stoffel
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef TOOLHEAD_CODES_H
#define TOOLHEAD_CODES_H

#define TH_VERSION			0x00
#define TH_INIT				0x01
#define TH_GET_TEMPERATURE		0x02
#define TH_SET_TEMPERATURE		0x03
#define TH_SET_MOTOR_1_PWM		0x04
#define TH_SET_MOTOR_2_PWM		0x05
#define TH_SET_MOTOR_1_RPM		0x06
#define TH_SET_MOTOR_2_RPM		0x07
#define TH_SET_MOTOR_1_DIRECTION	0x08
#define TH_SET_MOTOR_2_DIRECTION	0x09
#define TH_TOGGLE_MOTOR_1		0x0A
#define TH_TOGGLE_MOTOR_2		0x0B
#define TH_TOGGLE_FAN			0x0C
#define TH_TOGGLE_VALVE			0x0D
#define TH_SET_SERVO_1_POS		0x0E
#define TH_SET_SERVO_2_POS		0x0F
#define TH_FILAMENT_STATUS		0x10
#define TH_GET_MOTOR_1_RPM		0x11
#define TH_GET_MOTOR_2_RPM		0x12
#define TH_GET_MOTOR_1_PWM		0x13
#define TH_GET_MOTOR_2_PWM		0x14
#define TH_SELECT_TOOL			0x15
#define TH_IS_TOOL_READY		0x16

#endif // TOOLHEAD_CODES_H
