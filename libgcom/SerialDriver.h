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
