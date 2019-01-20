#include "Network.hpp"
#include "Shell.hpp"
#include "Graphic.hpp"
#include <sys/sysctl.h>
#include <sstream>
#include <cstdlib>
#include <sstream>
#include <mach/mach_host.h>
#include <net/route.h>
#include <net/if.h>


Network::Network() {}

Network::~Network() {}

Network::Network(IMonitorDisplay * display):
	_packageInTick(0),
	_packageOutTick(0),
	_mbInTick(0),
	_mbOutTick(0),
	_packageIn(0),
	_packageOut(0),
	_mbIn(0),
	_mbOut(0)
{
	getInfo();
	drawInfo(display);
}

Network::Network(Network const & src)
{
	static_cast<void>(src);
}

Network & Network::operator=(Network const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void Network::getInfo()
{
	unsigned long packageInPrev = _packageInTick;
	unsigned long packageOutPrev = _packageOutTick;
	unsigned long mbInPrev = _mbInTick;
	unsigned long mbOutPrev = _mbOutTick;

	_packageInTick = 0;
	_packageOutTick = 0;
	_mbInTick = 0;
	_mbOutTick = 0;

	int mib[6] = {CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST2, 0};

	// get data length first
	size_t len;
	sysctl(mib, 6, NULL, &len, NULL, 0);

	// get large enough buffer to hold data
	char data[len];
	sysctl(mib, 6, data, &len, NULL, 0);

	struct 	if_msghdr *ifm;
	char 	*pCur = data;
	char	*pEnd = pCur + len;

	while ( pCur < pEnd ) {
        // get msg header 1 location
		ifm = reinterpret_cast< struct if_msghdr * >( pCur );

        // skip msg header 1 lenght
		pCur += ifm->ifm_msglen;

        // test if msg type concerns in/out bytes or packets
		if ( ifm->ifm_type == RTM_IFINFO2) {

            // get msg header 2 location
			struct if_msghdr2 *if2m = reinterpret_cast< struct if_msghdr2 * > ( ifm );

            // get values from msg header 2 and increment in/out bytes or packets
			if( if2m->ifm_data.ifi_type != 18 ) {
				_packageInTick	+= if2m->ifm_data.ifi_opackets;
				_packageOutTick += if2m->ifm_data.ifi_ipackets;
				_mbInTick += if2m->ifm_data.ifi_obytes;
				_mbOutTick += if2m->ifm_data.ifi_ibytes;
			}
		}
	}

	_packageIn = _packageInTick - packageInPrev;
	_packageOut = _packageOutTick - packageOutPrev;
	_mbIn = _mbInTick - mbInPrev;
	_mbOut = _mbOutTick - mbOutPrev;

	std::stringstream ss;
	ss << "Package In/Out: " << _packageIn<< "/" << _packageOut;
	_package = ss.str();
	ss.str("");

	ss << "MB In/Out     : " << _mbIn / 1024 << "KB/" << _mbOut / 1024 << "KB";
	_mb = ss.str();
}

void Network::drawInfo(IMonitorDisplay * display)
{
	if (Shell * dis = dynamic_cast<Shell *>(display))
	{
		dis->putInfo("---------------------------------------------------");
		dis->putInfo("Network");
		dis->editY(1);
		dis->putInfo(_package);
		dis->putInfo(_mb);
		dis->putInfo("---------------------------------------------------");
	}
	else if (Graphic * dis = dynamic_cast<Graphic *>(display))
	{
		dis->putInfo("---------------------------------------------------");
		dis->putInfo("Network");
		dis->editY(12);
		dis->putInfo(_package);
		dis->putInfo(_mb);
		dis->putInfo("---------------------------------------------------");
	}
}