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
	*memoryPointer += 1;
}