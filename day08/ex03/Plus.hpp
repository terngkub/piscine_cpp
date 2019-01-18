#ifndef PLUS_HPP
# define PLUS_HPP

#include "IInstruction.hpp"

class Plus : public IInstruction
{
public:
	Plus();
	~Plus();
	void execute(char * memoryPointer);
};

#endif