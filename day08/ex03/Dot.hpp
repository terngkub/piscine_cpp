#ifndef DOT_HPP
# define DOT_HPP

#include "AInstruction.hpp"

class Dot : public AInstruction
{
public:
	Dot();
	~Dot();
	void execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index);

private:
	Dot(Dot const & src);
	Dot & operator=(Dot const & rhs);
};

#endif