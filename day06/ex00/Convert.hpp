#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>

class Convert
{
public:
	Convert(char c);
	Convert(double nb);
	~Convert();

	double	getDouble() const;
	float	getFloat() const;
	int		getInt() const;
	char	getChar() const;

private:
	Convert();
	Convert(Convert const & src);
	Convert & operator=(Convert const & rhs);

	char	_char;
	int		_int;
	float	_float;
	double	_double;
};

std::ostream & operator<<(std::ostream & o, Convert const & rhs);

#endif