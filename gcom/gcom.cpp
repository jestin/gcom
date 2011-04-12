#include <SerialDriver.h>
#include <CommandPackage.h>
#include <ReplyPackage.h>
#include <iostream>

int main(int argc, char* argv[])
{
	Serial_Options options;
	SerialDriver::InitializeOptions(&options);

	if(argc > 1)
	{
		options.port = argv[1];
	}
	else
	{
		options.port = "/dev/ttyUSB0";
	}

	SerialDriver driver(options);
	driver.whoami();
	CommandPackage command;
}
