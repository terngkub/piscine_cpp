#include "IInstruction.hpp"
#include <iostream>

IInstruction::~IInstruction()
{}

void IInstruction::execute(char * memoryPointer)
{
	std::cout << "execute interface\n";
	static_cast<void>(memoryPointer);
}