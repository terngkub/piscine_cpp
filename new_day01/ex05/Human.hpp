#pragma once
#include "Brain.hpp"

class Human
{
public:
	Human();
	std::string	identify() const;
	Brain		&getBrain();

private:
	Brain _brain;
};