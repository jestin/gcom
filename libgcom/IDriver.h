#ifndef IDRIVER_H
#define IDRIVER_H

#include "CommandPackage.h"
#include "ReplyPackage.h"

class IDriver
{
	public:
		virtual bool Initialize() = 0;
		virtual ReplyPackage Send(CommandPackage package) = 0;
	private:
};

#endif // IDRIVER_H
