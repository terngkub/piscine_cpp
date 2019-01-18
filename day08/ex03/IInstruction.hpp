#ifndef IINSTRUCTION_HPP
# define IINSTRUCTION_HPP

class IInstruction
{
public:
	virtual ~IInstruction();
	virtual void execute(char * memoryPointer);
};

#endif