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
