#include "Plus.hpp"
#include <iostream>

Plus::Plus()
{
}

Plus::~Plus()
{
}

void Plus::execute(char * memoryPointer)
{
	std::cout << "execute +\n";
	*memoryPointer += 1;
}