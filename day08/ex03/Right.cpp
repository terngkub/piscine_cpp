#include "Right.hpp"
#include <iostream>

Right::Right()
{
	_type = '>';
}

Right::~Right()
{
}


void Right::execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index)
{
	static_cast<void>(it);
	static_cast<void>(itb);
	static_cast<void>(ite);
	static_cast<void>(memory);
	index += 1;
	// handle out of bound case
}