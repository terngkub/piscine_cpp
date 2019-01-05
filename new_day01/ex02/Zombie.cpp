#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
: _type("default_type"),
_name("default_name")
{
	std::cout << "<" << _name << "(" << _type << ")> is created.\n";
}

Zombie::Zombie(std::string type, std::string name)
: _type(type),
_name(name)
{
	std::cout << "<" << _name << "(" << _type << ")> is created.\n";
}

Zombie::~Zombie()
{
	std::cout << "<" << _name << "(" << _type << ")> is dead.\n";
}

void Zombie::setType(std::string type)
{
	_type = type;
}

void Zombie::setName(std::string name)
{
	_name = name;
}

void Zombie::announce() const
{
	std::cout << "<" << _name << "(" << _type << ")> Braiiiiiiinnnssss...\n";
}
