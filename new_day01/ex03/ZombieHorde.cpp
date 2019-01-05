#include "ZombieHorde.hpp"
#include <iostream>

ZombieHorde::ZombieHorde(int N)
: _size(N)
{
	std::cout << "A zombie horde of size " << _size << " is created.\n";
	_zombies = new Zombie[N];

	std::string name_array[] = {"AAA", "BBB", "CCC", "DDD", "EEE"};
	for (int i = 0; i < _size; i++)
		_zombies[i].setName(name_array[rand() % 5]);
}

ZombieHorde::~ZombieHorde()
{
	delete [] _zombies;
	std::cout << "A zombie horde of size " << _size << " is destroyed.\n";
}

void ZombieHorde::announce() const
{
	for (int i = 0; i < _size; i++)
		_zombies[i].announce(); 
}