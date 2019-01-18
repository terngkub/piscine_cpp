#include "Dot.hpp"
#include <iostream>

Dot::Dot()
{
}

Dot::~Dot()
{
}

void Dot::execute(char * memoryPointer)
{
	std::cout << *memoryPointer;
}