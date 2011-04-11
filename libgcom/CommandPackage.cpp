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
