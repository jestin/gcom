/*
 S3GPackage.cpp

 Base class for Sanguino based motherboard command packages.  Might
 also work for Arduino Mega based motherboards, but I haven't checked.
     
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

#include "S3GPackage.h"
#include <stdlib.h>

S3GPackage::S3GPackage()
{
	start = 0xD5;
	length = 0;
	payload = NULL;
	checksum = 0x00;
}

S3GPackage::~S3GPackage()
{
}

uint8_t S3GPackage::CRC()
{
	if(payload == NULL)
	{
		return 0xFF;
	}

	uint8_t crc = 0;

	for(int i = 0; i < length; i++)
	{
		crc = (crc ^ payload[i]) & 0xFF;
		for (int i = 0; i < 8; i++)
		{
			if ((crc & 0x01) != 0)
			{
				crc = ((crc >> 1) ^ 0x8C) & 0xFF;
			}
			else
			{
				crc = (crc >> 1) & 0xFF;
			}
		}
	}

	return crc;
}

uint8_t S3GPackage::Code()
{
	if(payload)
	{
		return payload[0];
	}

	return 0xFF;
}

uint8_t* S3GPackage::Buffer()
{
	uint8_t* buffer = (uint8_t*)malloc(length + 3);

	buffer[0] = start;
	buffer[1] = length;
	for(int i = 0; i < length; i++)
	{
		buffer[i+2] = payload[i];
	}
	buffer[length+2] = checksum;

	return buffer;
}
