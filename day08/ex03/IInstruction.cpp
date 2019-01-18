#include "IInstruction.hpp"
#include <iostream>

IInstruction::~IInstruction()
{}

void IInstruction::execute(char * memoryPointer)
{
	static_cast<void>(memoryPointer);
}