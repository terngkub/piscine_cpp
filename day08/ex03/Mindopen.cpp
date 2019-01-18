#include "Mindopen.hpp"
#include <iostream>
#include <fsteram>

Mindopen::Mindopen(std::string filename) :
	_memoryPointer(_memory)
{
	std::ifstream ifs(filename);
	if (!ifs.is_open())
	{
		std::cerr << "can't open file\n";
	}

	char c = ifs.get();
	while (ifs.good())
	{
		addInstruction()

	}

	ifs.close();
}

Mindopen::~Mindopen
{

}

void Mindopen::execute()
{
	while (!_instructionQueue.empty())
	{
		_instructionQueue.front()->execute(_memoryPointer);
		_instructionQueue.pop();
	}
}

void Mindopen::addInstruction(IInstruction * instruction)
{
	_instructionQueue.push(instruction);
}