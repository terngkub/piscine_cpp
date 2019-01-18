#ifndef DOT_HPP
# define DOT_HPP

#include "IInstruction.hpp"

class Dot : public IInstruction
{
public:
	Dot();
	~Dot();
	void execute(char * memoryPointer);
};

#endif