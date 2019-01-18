#include "OpenBracket.hpp"
#include <iostream>

OpenBracket::OpenBracket()
{
	_type = '[';
}

OpenBracket::~OpenBracket()
{
}

void OpenBracket::execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index)
{
	static_cast<void>(itb);
	if (memory[index] == 0)
	{
		while (it != ite && (*it)->getType() != ']' )
		{
			++it;
		}
	}
}