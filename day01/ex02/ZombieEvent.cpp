#include "ZombieEvent.hpp"
#include <iostream>

ZombieEvent::ZombieEvent() : _type("default_type")
{
	std::cout << "A zombie event is created.\n";
}

ZombieEvent::~ZombieEvent()
{
	std::cout << "A zombie event is ended.\n";
}

void ZombieEvent::setZombieType(std::string type)
{
	_type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	return new Zombie(_type, name);
}

Zombie* ZombieEvent::randomChump()
{
	std::string name_array[] = {"AAA", "BBB", "CCC", "DDD", "EEE"};
	return newZombie(name_array[rand() % 5]);
}