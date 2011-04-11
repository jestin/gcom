#include "SerialDriver.h"
#include <iostream>
#include "motherboard_codes.h"
#include "toolhead_codes.h"

using namespace std;

SerialDriver::SerialDriver(string port, unsigned int baud_rate)
: io(), serial(io, port)
{
	this->port = port;
	serial.set_option(serial_port_base::baud_rate(baud_rate));
	serial.set_option(serial_port_base::parity(serial_port_base::parity::none));
	serial.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));
	//serial.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
}


SerialDriver::~SerialDriver()
{
}

void SerialDriver::whoami()
{
	cout << port << endl;
}

bool SerialDriver::Initialize()
{
	uint8_t* params = (uint8_t*) malloc(1);
	CommandPackage command(MB_VERSION, params, 1);
	
	ReplyPackage reply = Send(command);

	if(reply.Reply() == 1)
	{
		return true;
	}

	return false;
}

ReplyPackage SerialDriver::Send(CommandPackage package)
{
	ReplyPackage reply;

	// send the command package
	boost::asio::write(serial, boost::asio::buffer(package.Buffer(), package.PackageLength()));

	// read the reply
	uint8_t byte;
	uint8_t* buffer = NULL;

	return reply;
}
