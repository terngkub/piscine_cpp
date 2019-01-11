#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void testScavTrap()
{
	// Testing FragTrap
	std::cout << "Testing ScavTrap\n";
	std::cout << "-------------------------------------\n\n";

	// Constructors
	ScavTrap a;
	ScavTrap b("Bob");
	ScavTrap c(a);
	ScavTrap d;

	d = b;

	std::cout
		<< "\na's name: " << a.getName()
		<< "\nb's name: " << b.getName()
		<< "\nc's name: " << c.getName()
		<< "\nd's name: " << d.getName() << "\n\n";

	// Attacks
	a.rangedAttack("enemy1");
	a.meleeAttack("enemy2");
	std::cout << "\n";

	// Take damage
	std::cout << "Hit points: " << a.getHitPoints() << "\n";
	a.takeDamage(30);
	std::cout << "Hit points: " << a.getHitPoints() << "\n";
	a.takeDamage(90);
	std::cout << "Hit points: " << a.getHitPoints() << "\n";
	a.takeDamage(10);
	std::cout << "Hit points: " << a.getHitPoints() << "\n";
	a.beRepaired(20);
	std::cout << "Hit points: " << a.getHitPoints() << "\n";
	a.beRepaired(110);
	std::cout << "Hit points: " << a.getHitPoints() << "\n";
	std::cout << "\n";

	// challengeNewComer
	a.challengeNewcomer();
	a.challengeNewcomer();
	a.challengeNewcomer();
	a.challengeNewcomer();
	a.challengeNewcomer();
	std::cout << "\n";
}

void testFragTrap()
{
	// Testing FragTrap
	std::cout << "Testing FragTrap\n";
	std::cout << "-------------------------------------\n\n";

	// Constructors
	FragTrap a;
	FragTrap b("Bob");
	FragTrap c(a);
	FragTrap d;

	d = b;

	std::cout
		<< "\na's name: " << a.getName()
		<< "\nb's name: " << b.getName()
		<< "\nc's name: " << c.getName()
		<< "\nd's name: " << d.getName() << "\n\n";

	// Attacks
	a.rangedAttack("enemy1");
	a.meleeAttack("enemy2");
	std::cout << "\n";

	// Take damage
	std::cout << "Hit points: " << a.getHitPoints() << "\n";
	a.takeDamage(30);
	std::cout << "Hit points: " << a.getHitPoints() << "\n";
	a.takeDamage(90);
	std::cout << "Hit points: " << a.getHitPoints() << "\n";
	a.takeDamage(10);
	std::cout << "Hit points: " << a.getHitPoints() << "\n";
	a.beRepaired(20);
	std::cout << "Hit points: " << a.getHitPoints() << "\n";
	a.beRepaired(110);
	std::cout << "Hit points: " << a.getHitPoints() << "\n";
	std::cout << "\n";

	// Vaulthunter_dot_exe
	std::cout << "Energy points: " << a.getEnergyPoints() << "\n";
	a.vaulthunter_dot_exe("enemy3");
	std::cout << "Energy points: " << a.getEnergyPoints() << "\n";
	a.vaulthunter_dot_exe("enemy4");
	std::cout << "Energy points: " << a.getEnergyPoints() << "\n";
	a.vaulthunter_dot_exe("enemy5");
	std::cout << "Energy points: " << a.getEnergyPoints() << "\n";
	a.vaulthunter_dot_exe("enemy6");
	std::cout << "Energy points: " << a.getEnergyPoints() << "\n";
	a.vaulthunter_dot_exe("enemy7");
	std::cout << "\n";
}

int	main(void)
{
	testFragTrap();
	std::cout << "\n";
	testScavTrap();
	return (0);
}