#include <iostream>
#include "FragTrap.hpp"

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

	// Attributes
	std::cout
		<< "Hit points: " << a.getHitPoints()
		<< "\nMax hit points: " << a.getMaxHitPoints()
		<< "\nEnergy points: " << a.getEnergyPoints()
		<< "\nMax energy points: " << a.getMaxEnergyPoints()
		<< "\nLevel: " << a.getLevel()
		<< "\nName: " << a.getName()
		<< "\nMelee attack damage: " << a.getMeleeAttackDamage()
		<< "\nRanged attack damage: " << a.getRangedAttackDamage()
		<< "\nArmor damage reduction: " << a.getArmorDamageReduction() << "\n\n";

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
	return (0);
}