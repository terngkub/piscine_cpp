#include "CloseBracket.hpp"
#include <iostream>

CloseBracket::CloseBracket()
{
	_type = ']';
}

CloseBracket::~CloseBracket()
{
}

void CloseBracket::execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index)
{
	static_cast<void>(ite);
	if (memory[index] != 0)
	{
		while (it != itb && (*it)->getType() != '[' )
		{
			--it;
		}
	}
}