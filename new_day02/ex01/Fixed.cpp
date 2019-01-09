#include <cmath>
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default contructor called\n";
}

Fixed::Fixed(int value)
{
	std::cout << "Int contructor called\n";
	_rawBits = value * pow(2, _fractionalBits);
}

Fixed::Fixed(float value)
{
	std::cout << "Float contructor called\n";
	_rawBits = roundf(value * pow(2, _fractionalBits));
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
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float Fixed::toFloat() const
{
	return _rawBits / pow(2, _fractionalBits);
}

int Fixed::toInt() const
{
	return (int)(_rawBits / pow(2, _fractionalBits));
}

std::ostream & operator<<(std::ostream & o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}