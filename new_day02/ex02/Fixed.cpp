#include <cmath>
#include <iostream>
#include "Fixed.hpp"

// Constructors & destructor

Fixed::Fixed() : _rawBits(0)
{
}

Fixed::Fixed(int value)
{
	_rawBits = value * pow(2, _fractionalBits);
}

Fixed::Fixed(float value)
{
	_rawBits = roundf(value * pow(2, _fractionalBits));
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::~Fixed()
{
}


// Assignation operator

Fixed & Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		_rawBits = rhs.getRawBits();
	return *this;
}


// Comparison operators

bool Fixed::operator>(Fixed const &rhs) const
{
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return this->getRawBits() == rhs.getRawBits();

}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return this->getRawBits() != rhs.getRawBits();
}


// Arithmetic operators

Fixed Fixed::operator+(Fixed const &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}


// Increment & decrement operators

Fixed & Fixed::operator++()
{
	_rawBits += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed & Fixed::operator--()
{
	_rawBits -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}


// Member functions

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


// Stream operator

std::ostream & operator<<(std::ostream & o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}


// Non-member functions

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	return a <= b ? a : b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	return a >= b ? a : b;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	return a <= b ? a : b;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	return a >= b ? a : b;
}