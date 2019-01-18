#ifndef AINSTRUCTION_HPP
# define AINSTRUCTION_HPP

#include <vector>
#include <string>

class AInstruction;

typedef std::vector<AInstruction *>::iterator iterator;

class AInstruction
{
public:
	AInstruction();
	virtual ~AInstruction();
	virtual void execute(iterator & it, iterator & itb, iterator & ite, char * memory, int & index);
	char getType() const;

protected:
	char _type;

private:
	AInstruction(AInstruction const & src);
	AInstruction & operator=(AInstruction const & rhs);
};

#endif