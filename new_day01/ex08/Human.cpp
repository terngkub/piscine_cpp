#include <iostream>
#include "Human.hpp"

void Human::meleeAttack(std::string const & target)
{
	std::cout << "Melee attack to " << target << ".\n";
}

void Human::rangedAttack(std::string const & target)
{
	std::cout << "Ranged attack to " << target << ".\n";
}

void Human::intimidatingShout(std::string const & target)
{
	std::cout << "Intimidating shout to " << target << ".\n";
}

void Human::action(std::string const & action_name, std::string const & target)
{
	std::string action_array[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	void (Human::*function_array[])(std::string const &) = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

	for (int i = 0; i < 3; i++)
		if (action_name == action_array[i])
			(this->*function_array[i])(target);
}
