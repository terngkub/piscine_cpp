#include "DateTime.hpp"
#include "Shell.hpp"
#include "Graphic.hpp"
#include <time.h>

DateTime::DateTime() {}
DateTime::~DateTime() {}

DateTime::DateTime(IMonitorDisplay * display)
{
	getInfo();
	drawInfo(display);
}

DateTime::DateTime(DateTime const & src)
{
	static_cast<void>(src);
}

DateTime & DateTime::operator=(DateTime const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void DateTime::getInfo()
{
	time_t		now;
	struct tm * localTime;
	char		dateTime[128];

	now = time(NULL);
	localTime = localtime(&now);
	strftime(dateTime, sizeof(dateTime), "%d/%m/%Y-%H:%M:%S", localTime);
	_dateTime = std::string(dateTime);
}

void DateTime::drawInfo(IMonitorDisplay * display)
{
	if (Shell * dis = dynamic_cast<Shell *>(display))
	{
		dis->putInfo("---------------------------------------------------");
		dis->putInfo("Date/Time");
		dis->editY(1);
		dis->putInfo(_dateTime);
		dis->putInfo("---------------------------------------------------");
	}
	else if (Graphic * dis = dynamic_cast<Graphic *>(display))
	{
		dis->putInfo("---------------------------------------------------");
		dis->putInfo("Date/Time");
		dis->editY(12);
		dis->putInfo(_dateTime);
		dis->putInfo("---------------------------------------------------");
	}
}