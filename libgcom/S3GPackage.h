/*
 S3GPackage.h

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

#ifndef S3GPACKAGE_H
#define S3GPACKAGE_H

#include <cstddef>
#include <stdint.h>

#include "motherboard_codes.h"
#include "toolhead_codes.h"

class S3GPackage
{
public:	S3GPackage();	~S3GPackage();

	uint8_t CommandLength() { return length; }
	uint8_t PackageLength() { return length + 3; }
	uint8_t* Buffer();

protected:
	uint8_t start;
	uint8_t length;
	uint8_t* payload;
	uint8_t checksum;

	uint8_t Code();
	uint8_t CRC();
private:
};

#endif // S3GPACKAGE_H
