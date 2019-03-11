#include "Minus.hpp"
#include <iostream>

Minus::Minus()
{
	_type = '-';
}

Minus::~Minus()
{
}

void Minus::execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index)
{
	static_cast<void>(it);
	static_cast<void>(itb);
	static_cast<void>(ite);
	memory[index] += 1;
}