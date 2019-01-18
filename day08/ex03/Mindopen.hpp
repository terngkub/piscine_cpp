#ifndef MINDOPEN_HPP
# define MINDOPEN_HPP

#include <queue>
#include "IInstruction.hpp"

class Mindopen
{
public:
	Mindopen(std::string filename);

	void execute();
	void addInstruction(IInstruction * instruction);

private:
	Mindopen();

	char _memory[30000];
	char * _memoryPointer;
	std::queue<IInstruction *> _instructionQueue;
};

#endif