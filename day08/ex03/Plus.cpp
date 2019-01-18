#include "Plus.hpp"
#include <iostream>

Plus::Plus()
{
	_type = '+';
}

Plus::~Plus()
{
}

void Plus::execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index)
{
	static_cast<void>(it);
	static_cast<void>(itb);
	static_cast<void>(ite);
	memory[index] += 1;
}