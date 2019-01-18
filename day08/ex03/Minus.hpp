#ifndef MINUS_HPP
# define MINUS_HPP

#include "AInstruction.hpp"

class Minus : public AInstruction
{
public:
	Minus();
	~Minus();
	void execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index);

private:
	Minus(Minus const & src);
	Minus & operator=(Minus const & rhs);
};

#endif