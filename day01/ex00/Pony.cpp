#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string name)
: _name(name)
{
	std::cout << _name << " was born.\n";
}

Pony::~Pony()
{
	std::cout << _name << " was dead.\n";
}

void Pony::announce() const
{
	std::cout << "My name is " << _name << "\n";
}