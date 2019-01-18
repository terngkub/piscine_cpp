#ifndef OPENBRACKET_HPP
# define OPENBRACKET_HPP

#include "AInstruction.hpp"

class OpenBracket : public AInstruction
{
public:
	OpenBracket();
	~OpenBracket();
	void execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index);

private:
	OpenBracket(OpenBracket const & src);
	OpenBracket & operator=(OpenBracket const & rhs);
};

#endif