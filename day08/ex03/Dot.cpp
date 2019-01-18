#include "Dot.hpp"
#include <iostream>

Dot::Dot()
{
	_type = '.';
}

Dot::~Dot()
{
}

void Dot::execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index)
{
	static_cast<void>(it);
	static_cast<void>(itb);
	static_cast<void>(ite);
	std::cout << memory[index];
}