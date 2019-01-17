#include "Convert.hpp"
#include <cstdlib>
#include <cmath>
#include <limits>
#include <iomanip>

Convert::Convert()
{
}

Convert::Convert(char c) :
	_char(c),
	_int(static_cast<int>(c)),
	_float(static_cast<float>(c)),
	_double(static_cast<double>(c))
{
}

Convert::Convert(double nb) :
	_char(static_cast<char>(nb)),
	_int(static_cast<int>(nb)),
	_float(static_cast<float>(nb)),
	_double(nb)
{
}

Convert::~Convert()
{
}

Convert::Convert(Convert const & src)
{
	*this = src;
}

Convert & Convert::operator=(Convert const & rhs)
{
	(void)rhs;
	return *this;
}

double Convert::getDouble() const
{
	return _double;
}

float Convert::getFloat() const
{
	return _float;
}

int Convert::getInt() const
{
	return _int;
}

char Convert::getChar() const
{
	return _char;
}

std::ostream & operator<<(std::ostream & o, Convert const & rhs)
{
	char _char = rhs.getChar();
	int _int = rhs.getInt();
	float _float = rhs.getFloat();
	double _double = rhs.getDouble();

	if (std::isnan(_double) || std::isinf(_double))
		o << "char: impossible\n" << "int: impossible\n";
	else
	{
		if (_double < std::numeric_limits<char>::lowest() || _double > std::numeric_limits<char>::max())
			o << "char: overflow\n";
		else if (!isprint(_int))
			o << "char: Non displayable\n";
		else
			o << "char: '" << _char << "'\n";

		if (_double < std::numeric_limits<int>::lowest() || _double > std::numeric_limits<int>::max())
			o << "int: overflow\n";
		else
			o << "int: " << _int << "\n";
	}

	o << std::fixed << std::setprecision(1);
	o << "float: " << _float << "f\n";
	o << "double: " << _double << "\n";

	return o;
}
