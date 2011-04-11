/*
 SerialDriver.cpp

 Base class for all serial drivers.
     
 Part of the gcom project
 Copyright (c) 2011 Jestin Stoffel
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
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
