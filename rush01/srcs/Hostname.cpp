#include "Hostname.hpp"
#include "Shell.hpp"
#include "Graphic.hpp"
#include <unistd.h>
#include <climits>

Hostname::Hostname() {}
Hostname::~Hostname() {}

Hostname::Hostname(IMonitorDisplay * display)
{
	getInfo();
	drawInfo(display);
}

Hostname::Hostname(Hostname const & src)
{
	static_cast<void>(src);
}

Hostname & Hostname::operator=(Hostname const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void Hostname::getInfo()
{
	char hostname[_SC_HOST_NAME_MAX];
	gethostname(hostname, _SC_HOST_NAME_MAX);
	_hostname = std::string(hostname);

	char username[1024];
	getlogin_r(username, 1024);
	_username = std::string(username);
}

void Hostname::drawInfo(IMonitorDisplay * display)
{
	if (Shell * dis = dynamic_cast<Shell *>(display))
	{
		dis->putInfo("---------------------------------------------------");
		dis->putInfo("Hostname/Username");
		dis->editY(1);
		dis->putInfo("hostname: " + _hostname);
		dis->putInfo("username: " + _username);
		dis->putInfo("---------------------------------------------------");
	}
	else if (Graphic * dis = dynamic_cast<Graphic *>(display))
	{
		dis->putInfo("---------------------------------------------------");
		dis->putInfo("Hostname/Username");
		dis->editY(12);
		dis->putInfo("hostname: " + _hostname);
		dis->putInfo("username: " + _username);
		dis->putInfo("---------------------------------------------------");
	}
}