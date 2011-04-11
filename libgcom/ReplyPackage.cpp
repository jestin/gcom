#include "ReplyPackage.h"

ReplyPackage::ReplyPackage()
	: S3GPackage()
{
}

ReplyPackage::~ReplyPackage()
{
}

uint8_t ReplyPackage::Reply()
{
	return Code();
}
