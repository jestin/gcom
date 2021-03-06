/*
 CommandPackage.cpp

 This class represents the command package expected by Gen3 electronics.
     
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

#include "CommandPackage.h"
#include "stdlib.h"

CommandPackage::CommandPackage()
	: S3GPackage()
{
}

CommandPackage::CommandPackage(uint8_t code, uint8_t* params, size_t size)
	: S3GPackage()
{
	length = (uint8_t) size;
	payload = (uint8_t*) malloc(size);
	for(int i = 0; i < length; i++)
	{
		payload[i] = params[i];
	}
	checksum = CRC();
}

CommandPackage::~CommandPackage()
{
}

uint8_t CommandPackage::Command()
{
	return Code();
}
