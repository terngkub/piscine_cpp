#include "AInstruction.hpp"
#include <iostream>

AInstruction::AInstruction()
{}

AInstruction::~AInstruction()
{}

void AInstruction::execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index)
{
	static_cast<void>(it);
	static_cast<void>(itb);
	static_cast<void>(ite);
	static_cast<void>(memory);
	static_cast<void>(index);
}

char AInstruction::getType() const
{
	return _type;
}