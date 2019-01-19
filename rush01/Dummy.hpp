#ifndef DUMMY_HPP
# define DUMMY_HPP

#include <string>
#include "IMonitorModule.hpp"

class Dummy : public IMonitorModule
{
public:
	Dummy();
	~Dummy();
	std::string getInfo();
};

#endif