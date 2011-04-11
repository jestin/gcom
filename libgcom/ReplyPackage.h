#ifndef REPLYPACKAGE_H
#define REPLYPACKAGE_H

#include "S3GPackage.h"

class ReplyPackage : S3GPackage
{
	public:
		ReplyPackage();
		~ReplyPackage();

		uint8_t Reply();
	protected:
	private:
};

#endif // REPLYPACKAGE_H
