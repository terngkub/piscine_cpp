#ifndef CLOSEBRACKET_HPP
# define CLOSEBRACKET_HPP

#include "AInstruction.hpp"

class CloseBracket : public AInstruction
{
public:
	CloseBracket();
	~CloseBracket();
	void execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index);

private:
	CloseBracket(CloseBracket const & src);
	CloseBracket & operator=(CloseBracket const & rhs);
};

#endif