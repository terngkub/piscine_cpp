#include "OS.hpp"
#include "Shell.hpp"
#include "Graphic.hpp"
#include <sys/sysctl.h>

OS::OS() {}
OS::~OS() {}

OS::OS(IMonitorDisplay * display)
{
	getInfo();
	drawInfo(display);
}

OS::OS(OS const & src)
{
	static_cast<void>(src);
}

OS & OS::operator=(OS const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void OS::getInfo()
{
	getType();
	getVersion();
	getRelease();
}

void OS::getType()
{
	size_t size = 128;
	char buf[size];

	sysctlbyname("kern.ostype", &buf, &size, NULL, 0);
	_type = std::string(buf);
}

void OS::getRelease()
{
	size_t size = 128;
	char buf[size];

	sysctlbyname("kern.osrelease", &buf, &size, NULL, 0);
	_release = std::string(buf);
}

void OS::getVersion()
{
	size_t size = 128;
	char buf[size];

	sysctlbyname("kern.osversion", &buf, &size, NULL, 0);
	_version = std::string(buf);
}


void OS::drawInfo(IMonitorDisplay * display)
{
	if (Shell * dis = dynamic_cast<Shell *>(display))
	{
		dis->putInfo("---------------------------------------------------");
		dis->putInfo("OS");
		dis->editY(1);
		dis->putInfo("Type: " + _type);
		dis->putInfo("Release: " + _release);
		dis->putInfo("Version: " + _version);
		dis->putInfo("---------------------------------------------------");
	}
	else if (Graphic * dis = dynamic_cast<Graphic *>(display))
	{
		dis->putInfo("---------------------------------------------------");
		dis->putInfo("OS");
		dis->editY(12);
		dis->putInfo("Type: " + _type);
		dis->putInfo("Release: " + _release);
		dis->putInfo("Version: " + _version);
		dis->putInfo("---------------------------------------------------");
	}
}