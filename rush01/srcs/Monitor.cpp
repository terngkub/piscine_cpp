#include <ncurses.h>
#include "Monitor.hpp"
#include "Graphic.hpp"
#include "Shell.hpp"
#include "Hostname.hpp"
#include "OS.hpp"
#include "DateTime.hpp"
#include "CPU.hpp"
#include "RAM.hpp"
#include "Network.hpp"
#include <iostream>

Monitor::Monitor() :
	_display(new Shell()),
	_frameRate(1)
{
}

Monitor::Monitor(std::string mode) :
	_frameRate(1)
{
	if (mode == "-graphic")
		_display = new Graphic();
	else
		_display = new Shell();
}

Monitor::Monitor(Monitor const & src)
{
	static_cast<void>(src);
}

Monitor::~Monitor()
{
	for (std::vector<IMonitorModule *>::iterator it = _module.begin(); it != _module.end(); ++it)
		delete (*it);
	delete _display;
}

Monitor & Monitor::operator=(Monitor const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void Monitor::run()
{
	init();
	while(true)
	{
		if (_display->isClose())
			break;

		if (shouldUpdate())
		{
			update();
			render();
		}
	}
}

void Monitor::init()
{
	_module.push_back(new Hostname(_display));
	_module.push_back(new OS(_display));
	_module.push_back(new DateTime(_display));
	_module.push_back(new CPU(_display));
	_module.push_back(new RAM(_display));
	_module.push_back(new Network(_display));

	gettimeofday(&_loopStart, NULL);
	gettimeofday(&_loopStop, NULL);
	render();
}

bool Monitor::shouldUpdate()
{
	gettimeofday(&_loopStop, NULL);
	int duration = (_loopStop.tv_sec - _loopStart.tv_sec) * 1000000 + _loopStop.tv_usec - _loopStart.tv_usec;
	if (duration > (1000000 / _frameRate))
		return true;
	return false;
}

void Monitor::update()
{
	for (std::vector<IMonitorModule *>::iterator it = _module.begin(); it != _module.end(); ++it)
	{
		(*it)->getInfo();
		(*it)->drawInfo(_display);
	}
}

void Monitor::render()
{
	_display->render();
	_loopStart = _loopStop;
}
