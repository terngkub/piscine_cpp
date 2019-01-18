#include "Comma.hpp"
#include <iostream>

Comma::Comma()
{
	_type = ',';
}

Comma::~Comma()
{
}

void Comma::execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index)
{
	static_cast<void>(it);
	static_cast<void>(itb);
	static_cast<void>(ite);
	std::cin >> memory[index];
}