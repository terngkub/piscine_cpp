#pragma once
#include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(int N);
	~ZombieHorde();
	void announce() const;

private:
	int		_size;
	Zombie	*_zombies;
};