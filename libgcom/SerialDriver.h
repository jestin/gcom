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

class SerialDriver : IDriver
{
	public:
		SerialDriver(string port, unsigned int baud_rate);
		virtual ~SerialDriver();

		void whoami();

		bool Initialize();
		ReplyPackage Send(CommandPackage package);

	protected:
		io_service io;
		serial_port serial;
		string port;
		boost::asio::streambuf read_data;
	private:
};

#endif // GCOM_H
