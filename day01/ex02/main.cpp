#include "ZombieEvent.hpp"
#include <iostream>

void testZombieConstructor()
{
	std::cout << "Test: Zombie constructor\n\n";

	Zombie z1 = Zombie();
	z1.announce();
	std::cout << "\n";

	Zombie z2 = Zombie("walker", "Stack");
	z2.announce();
	std::cout << "\n";

	Zombie *z3 = new Zombie();
	z3->announce();
	delete z3;
	std::cout << "\n";

	Zombie *z4 = new Zombie("runner", "Heap");
	z4->announce();
	delete z4;
	std::cout << "\n";
}

void testZombieEvent()
{
	std::cout << "Test: ZombieEvent\n\n";

	ZombieEvent ze;
	std::cout << "\n";
	ze.setZombieType("crawler");

	Zombie *one = ze.newZombie("One");
	one->announce();
	delete one;
	std::cout << "\n";

	Zombie *two = ze.randomChump();
	two->announce();
	delete two;
	std::cout << "\n";

	Zombie *three = ze.randomChump();
	three->announce();
	delete two;
	std::cout << "\n";
}

int main()
{
	testZombieConstructor();
	std::cout << "\n\n";
	testZombieEvent();
	return 0;
}