#ifndef COMMA_HPP
# define COMMA_HPP

#include "AInstruction.hpp"

class Comma : public AInstruction
{
public:
	Comma();
	~Comma();
	void execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index);

private:
	Comma(Comma const & src);
	Comma & operator=(Comma const & rhs);
};

#endif