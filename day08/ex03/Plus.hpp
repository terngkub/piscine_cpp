#ifndef PLUS_HPP
# define PLUS_HPP

#include "AInstruction.hpp"

class Plus : public AInstruction
{
public:
	Plus();
	~Plus();
	void execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index);

private:
	Plus(Plus const & src);
	Plus operator=(Plus const & rhs);
};

#endif