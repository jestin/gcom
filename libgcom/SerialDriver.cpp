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

SerialDriver::SerialDriver(Serial_Options options)
: io(), serial(io, options.port)
{
	SetOptions(options);
	serial.set_option(options.baud_rate);
	serial.set_option(options.parity);
	serial.set_option(options.stopbits);
}


SerialDriver::~SerialDriver()
{
}

void SerialDriver::whoami()
{
	cout << options.port << endl;
}

void SerialDriver::SetOptions(Serial_Options options)
{
	this->options.port = options.port;
	this->options.baud_rate = options.baud_rate;
	this->options.parity = options.parity;
	this->options.databits = options.databits;
	this->options.stopbits = options.stopbits;
	this->options.debuglevel = options.debuglevel;
}

void SerialDriver::InitializeOptions(Serial_Options* options)
{
	options->port = "/dev/ttyUSB0"; // TODO default this to the first serial port found
	options->baud_rate = serial_port_base::baud_rate(38400);
	options->parity = serial_port_base::parity(serial_port_base::parity::none);
	options->databits = 1.0;
	options->stopbits = serial_port_base::stop_bits(serial_port_base::stop_bits::one);
	options->debuglevel = 0;
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
