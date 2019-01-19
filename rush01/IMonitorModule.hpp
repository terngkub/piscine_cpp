#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include <string>

class IMonitorModule
{
public:
	virtual ~IMonitorModule();
	virtual std::string getInfo() = 0;

private:

};

#endif