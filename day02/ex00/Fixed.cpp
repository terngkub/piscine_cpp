#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default contructor called\n";
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called\n";
	if (this != &rhs)
		_rawBits = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_rawBits = raw;
}