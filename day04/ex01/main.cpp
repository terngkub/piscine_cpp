#include <iostream>
#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

void subjectTest()
{
	std::cout << "Test from the subject\n";
	std::cout << "____________________________\n\n";

	Character * zaz = new Character("zaz");

	std::cout << *zaz;

	Enemy * b = new RadScorpion();

	AWeapon * pr = new PlasmaRifle();
	AWeapon * pf = new PowerFist();

	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);

	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
}

void superMutantTest()
{
	std::cout << "\n\nSuper Mutant Test\n";
	std::cout << "____________________________\n\n";

	Character * zaz = new Character("zaz");
	Enemy * b = new SuperMutant();
	Enemy * c = new SuperMutant();
	AWeapon * pf = new PowerFist();
	std::cout << "\n";

	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	std::cout << "\n";

	zaz->equip(pf);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	std::cout << "\n";

	zaz->attack(c);
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << *zaz;
}

int main()
{
	subjectTest();
	superMutantTest();
	return 0;
}