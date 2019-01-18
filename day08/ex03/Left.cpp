#include "Left.hpp"
#include <iostream>

Left::Left()
{
	_type = '<';
}

Left::~Left()
{
}

void Left::execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index)
{
	static_cast<void>(it);
	static_cast<void>(itb);
	static_cast<void>(ite);
	static_cast<void>(memory);
	index -= 1;
	// handle out of bound case;
}