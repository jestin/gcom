#include <SerialDriver.h>
#include <CommandPackage.h>
#include <ReplyPackage.h>
#include <iostream>

int main(int argc, char* argv[])
{
	string port;

	if(argc > 1)
	{
		port = argv[1];
	}
	else
	{
		port = "/dev/ttyUSB0";
	}

	SerialDriver driver(port, 38400);
	driver.whoami();
	CommandPackage command;
}
