/*
   SerialDriver.h

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

#ifndef SERIALDRIVER_H
#define SERIALDRIVER_H

#include "IDriver.h"
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

typedef struct
{
	string port;
	serial_port_base::baud_rate baud_rate;
	serial_port_base::parity parity;
	float databits;
	serial_port_base::stop_bits stopbits;
	int debuglevel;
}Serial_Options;

class SerialDriver : IDriver
{
	public:
		SerialDriver(Serial_Options options);
		virtual ~SerialDriver();

		void whoami();

		bool Initialize();
		ReplyPackage Send(CommandPackage package);

		void SetOptions(Serial_Options options);
		static void InitializeOptions(Serial_Options* options);

	protected:
		io_service io;
		serial_port serial;
		boost::asio::streambuf read_data;

		Serial_Options options;
	private:
};

#endif // GCOM_H
