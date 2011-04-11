#ifndef COMMANDPACKAGE_H
#define COMMANDPACKAGE_H

#include "S3GPackage.h"

class CommandPackage : public S3GPackage
{
	public:
		CommandPackage();
		CommandPackage(uint8_t code, uint8_t* params, size_t size);
		~CommandPackage();

		uint8_t Command();
	protected:
	private:
};

#endif // COMMANDPACKAGE_H
