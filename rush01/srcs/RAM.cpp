#include "RAM.hpp"
#include "Shell.hpp"
#include "Graphic.hpp"
#include <sstream>
#include <iomanip>
#include <mach/mach_host.h>
#include <sys/utsname.h>
#include <sys/sysctl.h>

RAM::RAM() :
	_total(0),
	_free(0),
	_active(0),
	_inactive(0),
	_wired(0)
{}

RAM::~RAM() {}

RAM::RAM(IMonitorDisplay * display)
{
	getInfo();
	drawInfo(display);
}

RAM::RAM(RAM const & src)
{
	static_cast<void>(src);
}

RAM & RAM::operator=(RAM const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void RAM::getInfo()
{
	mach_port_t	port = mach_host_self();
	vm_size_t	pageSize;

	if (KERN_SUCCESS != host_page_size(port, &pageSize))
		return;

	vm_statistics64_data_t	vmstat;
	mach_msg_type_number_t	count = sizeof(vmstat) / sizeof(pageSize);
	if (KERN_SUCCESS != host_statistics64(port, HOST_VM_INFO, reinterpret_cast<host_info_t>(&vmstat), &count))
		return;
	
	long long freeMem		= static_cast<int64_t>(vmstat.free_count) * static_cast<int64_t>(pageSize) / 1024 / 1024;
	long long activeMem		= static_cast<int64_t>(vmstat.active_count) * static_cast<int64_t>(pageSize) / 1024 / 1024;
	long long inactiveMem	= static_cast<int64_t>(vmstat.inactive_count) * static_cast<int64_t>(pageSize) / 1024 / 1024;
	long long wiredMem		= static_cast<int64_t>(vmstat.wire_count) * static_cast<int64_t>(pageSize) / 1024 / 1024;
	long long totalMem		= freeMem + activeMem + inactiveMem + wiredMem;

	double freePercent		= freeMem * 100.0 / totalMem;
	double activePercent	= activeMem * 100.0 / totalMem;
	double inactivePercent	= inactiveMem * 100.0 / totalMem;
	double wiredPercent		= wiredMem * 100.0 / totalMem;

	std::stringstream ss;
	ss << std::fixed;

	ss << "Total memory   :" << std::setw(6) << totalMem << "MB 100.00%";
	_total = ss.str();
	ss.str("");

	ss << std::setprecision(2);

	ss << "Free memory    :" << std::setw(6) << freeMem << "MB" << std::setw(7) << freePercent << "%";
	_free = ss.str();
	ss.str("");

	ss << "Active memory  :" << std::setw(6) << activeMem << "MB" << std::setw(7) << activePercent << "%";
	_active = ss.str();
	ss.str("");

	ss << "Inactive memory:" << std::setw(6) << inactiveMem << "MB" << std::setw(7) << inactivePercent << "%";
	_inactive = ss.str();
	ss.str("");

	ss << "Wired memory   :" << std::setw(6) << wiredMem << "MB" << std::setw(7) << wiredPercent << "%";
	_wired = ss.str();

}

void RAM::drawInfo(IMonitorDisplay * display)
{
	if (Shell * dis = dynamic_cast<Shell *>(display))
	{
		dis->putInfo("---------------------------------------------------");
		dis->putInfo("RAM");
		dis->editY(1);
		dis->putInfo(_total + "%");
		dis->putInfo(_free + "%");
		dis->putInfo(_active + "%");
		dis->putInfo(_inactive + "%");
		dis->putInfo(_wired + "%");
		dis->putInfo("---------------------------------------------------");
	}
	else if (Graphic * dis = dynamic_cast<Graphic *>(display))
	{
		dis->putInfo("---------------------------------------------------");
		dis->putInfo("RAM");
		dis->editY(12);
		dis->putInfo(_total);
		dis->putInfo(_free);
		dis->putInfo(_active);
		dis->putInfo(_inactive);
		dis->putInfo(_wired);
		dis->putInfo("---------------------------------------------------");
	}
}
