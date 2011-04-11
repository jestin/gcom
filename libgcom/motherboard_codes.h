/*
 motherboard_codes.h

 This file defines the codes that the Gen3 motherboard understands.
     
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

#ifndef MOTHERBOARD_CODES_H
#define MOTHERBOARD_CODES_H

#define MB_VERSION			0x00
#define MB_INIT				0x01
#define MB_GET_BUFFER			0x02
#define MB_CLEAR_BUFFER			0x03
#define MB_GET_POSITION			0x04
#define MB_GET_RANGE			0x05
#define MB_SET_RANGE			0x06
#define MB_ABORT			0x07
#define MB_PAUSE			0x08
#define MB_PROBE			0x09
#define MB_TOOL_QUERY			0x0A
#define MB_IS_FINISHED			0x0B
#define MB_READ_EEPROM			0x0C
#define MB_WRITE_EEPROM			0x0D
#define MB_CAPTURE_TO_FILE		0x0E
#define MB_END_CAPTURE			0x0F
#define MB_PLAYBACK_FILE		0x10
#define MB_RESET			0x11
#define MB_NEXT_FILENAME		0x12
#define MB_QUEUE_POINT_ABSOLUTE		0x81
#define MB_SET_POSITION_REGISTERS	0x82
#define MB_FIND_AXES_MINIMUM		0x83
#define MB_FIND_AXES_MAXIMUM		0x84
#define MB_DELAY			0x85
#define MB_CHANGE_TOOL			0x86
#define MB_WAIT_FOR_TOOL		0x87
#define MB_TOOL_COMMAND			0x88
#define MB_ENABE_AXES			0x89

#endif // MOTHERBOARD_CODES_H
