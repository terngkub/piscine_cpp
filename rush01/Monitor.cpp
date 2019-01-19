#include <ncurses.h>
#include "Monitor.hpp"
#include "Graphic.hpp"
#include "Shell.hpp"
#include "Dummy.hpp"
#include <iostream>

Monitor::Monitor() :
	_display(new Graphic()),
	_frameRate(1)
{
	_module.push_back(new Dummy());
	_module.push_back(new Dummy());
	_module.push_back(new Dummy());
	_module.push_back(new Dummy());
	_module.push_back(new Dummy());
	_module.push_back(new Dummy());
}

Monitor::~Monitor()
{
	delete _display;
	for (std::vector<IMonitorModule *>::iterator it = _module.begin(); it != _module.end(); ++it)
	{
		delete (*it);
	}
}

void Monitor::run()
{
	init();
	while(true)
	{
		char c = _display->getInput();
		if (c == 'q')
			break;

		//std::cout << "-";
		if (shouldUpdate())
		{
			std::cout << "+";
			update();
			render();
		}
	}
}

void Monitor::init()
{
	gettimeofday(&_loopStart, NULL);
	gettimeofday(&_loopStop, NULL);
	update();
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
		_display->putInfo((*it)->getInfo());
	}
}

void Monitor::render()
{
	_display->render();
	_loopStart = _loopStop;
}
