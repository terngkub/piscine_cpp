#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include <string>

class IMonitorDisplay
{
public:
	virtual ~IMonitorDisplay();
	virtual char getInput() = 0;
	virtual void putInfo(std::string str) = 0;
	virtual void render() = 0;
};

#endif