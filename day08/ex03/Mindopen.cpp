#include "Mindopen.hpp"
#include <iostream>

Mindopen::Mindopen() :
	_memoryPointer(_memory)
{
}

void Mindopen::execute()
{
	while (!_instructionQueue.empty())
	{
		IInstruction instruction = _instructionQueue.front();
		instruction.execute(_memoryPointer);
		_instructionQueue.pop();
		std::cout << "size: " << _instructionQueue.size() << "\n";
	}
}

void Mindopen::addInstruction(IInstruction instruction)
{
	_instructionQueue.push(instruction);
	std::cout << "size: " << _instructionQueue.size() << "\n";
}