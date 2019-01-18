#ifndef RIGHT_HPP
# define RIGHT_HPP

#include "AInstruction.hpp"

class Right : public AInstruction
{
public:
	Right();
	~Right();
	void execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index);

private:
	Right(Right const & src);
	Right operator=(Right const & rhs);
};

#endif