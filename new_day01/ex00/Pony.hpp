#pragma once
#include <string>

class Pony
{
public:
	Pony(std::string name);
	~Pony();
	void announce() const;

private:
	std::string _name;
	Pony();
};