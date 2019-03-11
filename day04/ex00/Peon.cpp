#include "Peon.hpp"
#include <iostream>

Peon::Peon() : Victim()
{
	std::cout << "Zog zog.\n";
}

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog.\n";
}

Peon::Peon(Peon const & src) : Victim(src)
{
	std::cout << "Zog zog.\n";
}

Peon::~Peon()
{
	std::cout << "Bleuark...\n";
}

void Peon::getPolymorphed() const
{
	std::cout << _name << " has been turned into a pink pony !\n";
}