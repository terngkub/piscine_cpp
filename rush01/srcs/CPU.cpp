#include "CPU.hpp"
#include "Shell.hpp"
#include "Graphic.hpp"
#include <sys/sysctl.h>
#include <sstream>
#include <cstdlib>
#include <sstream>
#include <mach/mach_host.h>
#include <iomanip>

CPU::CPU() {}
CPU::~CPU() {}

CPU::CPU(IMonitorDisplay * display) :
	_userTick(0),
	_systemTick(0),
	_idleTick(0)
{
	getInfo();
	drawInfo(display);
}

CPU::CPU(CPU const & src)
{
	static_cast<void>(src);
}

CPU & CPU::operator=(CPU const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void CPU::getInfo()
{
	unsigned long long userPrev = _userTick;
	unsigned long long systemPrev = _systemTick;
	unsigned long long idlePrev = _idleTick;

	getModel();
	getCores();

	mach_port_t					port = mach_host_self();
	host_cpu_load_info_data_t	cpustat;
	mach_msg_type_number_t		count = HOST_CPU_LOAD_INFO_COUNT;

	if (KERN_SUCCESS != host_statistics(port, HOST_CPU_LOAD_INFO, reinterpret_cast<host_info_t>(&cpustat), &count))
		return;
	
	_userTick = cpustat.cpu_ticks[0];
	_systemTick = cpustat.cpu_ticks[1];
	_idleTick = cpustat.cpu_ticks[2];

	unsigned long long user = _userTick - userPrev; 
	unsigned long long system = _systemTick - systemPrev; 
	unsigned long long idle = _idleTick - idlePrev; 
	unsigned long long total = user + system + idle;

	std::stringstream ss;
	ss << std::fixed << std::setprecision(2);

	ss << "User  :" << std::setw(6) << user * 100.0 / total << "%";
	_user = ss.str();
	ss.str("");

	ss << "System:" << std::setw(6) << system * 100.0 / total << "%";
	_system = ss.str();
	ss.str("");

	ss << "Idle  :" << std::setw(6) << idle * 100.0 / total << "%";
	_idle = ss.str();
	ss.str("");
}

void CPU::getModel()
{
	size_t sz = 128;
	char buf1[128];

	sysctlbyname("machdep.cpu.brand_string", &buf1, &sz, NULL, 0);
	_model = std::string(buf1);

}

void CPU::getCores()
{
	int cores;
	size_t sz = sizeof(int);

	sysctlbyname("machdep.cpu.core_count", &cores, &sz, NULL, 0);

	std::stringstream ss;
	ss << cores;
	_cores = ss.str();
}

void CPU::drawInfo(IMonitorDisplay * display)
{
	if (Shell * dis = dynamic_cast<Shell *>(display))
	{
		dis->putInfo("---------------------------------------------------");
		dis->putInfo("CPU");
		dis->editY(1);
		dis->putInfo("Model: " + _model);
		dis->putInfo("Cores: " + _cores);
		dis->putInfo(_user + "%");
		dis->putInfo(_system + "%");
		dis->putInfo(_idle + "%");
		dis->putInfo("---------------------------------------------------");
	}
	else if (Graphic * dis = dynamic_cast<Graphic *>(display))
	{
		dis->putInfo("---------------------------------------------------");
		dis->putInfo("CPU");
		dis->editY(12);
		dis->putInfo("Model: " + _model);
		dis->putInfo("Cores: " + _cores);
		dis->putInfo(_user);
		dis->putInfo(_system);
		dis->putInfo(_idle);
		dis->putInfo("---------------------------------------------------");
	}
}