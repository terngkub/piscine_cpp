#include <iostream>
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"

void subjectTest()
{
	std::cout << "Test from subject\n";
	std::cout << "__________________________\n\n";

	ISpaceMarine *bob = new TacticalMarine;
	ISpaceMarine *jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
}

void copyTest()
{
	std::cout << "\nCopy test\n";
	std::cout << "__________________________\n\n";

	ISpaceMarine *a = new TacticalMarine;
	ISpaceMarine *b = new AssaultTerminator;
	ISpaceMarine *c = new TacticalMarine;
	ISpaceMarine *d = new TacticalMarine;
	ISpaceMarine *e = new AssaultTerminator;

	Squad* sq1 = new Squad();
	sq1->push(a);
	sq1->push(b);
	sq1->push(c);
	sq1->push(d);
	std::cout << "\n";

	for (int i = 0; i < sq1->getCount(); ++i)
	{
		ISpaceMarine* cur = sq1->getUnit(i);
		cur->battleCry();
	}
	std::cout << "\n";

	Squad* sq2 = new Squad();
	sq2->push(e);
	*sq2 = *sq1;
	std::cout << "\n";

	for (int i = 0; i < sq2->getCount(); ++i)
	{
		ISpaceMarine* cur = sq2->getUnit(i);
		cur->battleCry();
	}
	std::cout << "\n";

	delete sq1;
	delete sq2;
}

int main()
{
	subjectTest();
	copyTest();
	return 0;
}