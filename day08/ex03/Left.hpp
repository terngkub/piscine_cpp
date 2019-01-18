#ifndef LEFT_HPP
# define LEFT_HPP

#include "AInstruction.hpp"

class Left : public AInstruction
{
public:
	Left();
	~Left();
	void execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index);
	
private:
	Left(Left const & src);
	Left operator=(Left const & rhs);
};

#endif