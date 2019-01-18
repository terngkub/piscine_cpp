#ifndef MINDOPEN_HPP
# define MINDOPEN_HPP

#include <queue>
#include "AInstruction.hpp"
#include "Left.hpp"
#include "Right.hpp"
#include "Plus.hpp"
#include "Minus.hpp"
#include "Dot.hpp"
#include "Comma.hpp"
#include "OpenBracket.hpp"
#include "CloseBracket.hpp"

class Mindopen
{
public:
	Mindopen(std::string filename);
	~Mindopen();

	void execute();
	void addInstruction(char c);

private:
	Mindopen();

	char _memory[30000];
	int _index;
	std::vector<AInstruction *> _instruction;

	Left * _left;
	Right * _right;
	Plus * _plus;
	Minus * _minus;
	Dot * _dot;
	Comma * _comma;
	OpenBracket * _openBracket;
	CloseBracket * _closeBracket;
};

#endif