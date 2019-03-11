#include "Mindopen.hpp"
#include <iostream>
#include <fstream>

Mindopen::Mindopen(std::string filename) :
	_index(0),
	_left(new Left()),
	_right(new Right()),
	_plus(new Plus()),
	_minus(new Minus()),
	_dot(new Dot()),
	_comma(new Comma()),
	_openBracket(new OpenBracket()),
	_closeBracket(new CloseBracket())
{
	std::ifstream ifs(filename);
	if (!ifs.is_open())
	{
		std::cerr << "can't open file\n";
		return ;
	}

	char c = ifs.get();
	while (ifs.good())
	{
		addInstruction(c);
		c = ifs.get();
	}

	ifs.close();
}

Mindopen::~Mindopen()
{
	delete _left;
	delete _right;
	delete _plus;
	delete _minus;
	delete _dot;
	delete _comma;
	delete _openBracket;
	delete _closeBracket;
}

void Mindopen::addInstruction(char c)
{
	if (c == '<')
		_instruction.push_back(_left);
	else if (c == '>')
		_instruction.push_back(_right);
	else if (c == '+')
		_instruction.push_back(_plus);
	else if (c == '-')
		_instruction.push_back(_minus);
	else if (c == '.')
		_instruction.push_back(_dot);
	else if (c == ',')
		_instruction.push_back(_comma);
	else if (c == '[')
		_instruction.push_back(_openBracket);
	else if (c == ']')
		_instruction.push_back(_closeBracket);
}

void Mindopen::execute()
{
	iterator it = _instruction.begin();
	iterator itb = _instruction.begin();
	iterator ite = _instruction.end();
	for (; it != ite; ++it)
	{
		try
		{
			(*it)->execute(it, itb, ite, _memory, _index);
		}
		catch(std::exception e)
		{
			throw(e);
		}
	}
}