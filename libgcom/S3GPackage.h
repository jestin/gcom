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
