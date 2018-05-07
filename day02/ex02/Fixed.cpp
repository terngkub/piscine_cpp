/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:47:30 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/07 19:07:40 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Constructors & Destructor

Fixed::Fixed(void) : rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = value * pow(2, this->fractionalBits);
}

Fixed::Fixed(float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(value * pow(2, this->fractionalBits));
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}


// Assignation Operator

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	
	if (this != &rhs)
		this->rawBits = rhs.getRawBits();

	return *this;
}


// Comparison Operators

bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->rawBits > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->rawBits < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->rawBits >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->rawBits <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->rawBits == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->rawBits != rhs.getRawBits());
}


// Arithmetic Operators

Fixed	Fixed::operator+(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}


// Functions

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return this->rawBits / pow(2, this->fractionalBits);
}

int		Fixed::toInt(void) const
{
	return (int)(this->rawBits / pow(2, this->fractionalBits));
}


// Non-member Functions

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

Fixed const &	min(Fixed const & lhs, Fixed const & rhs)
{
	return (lhs <= rhs ? lhs : rhs);
}

Fixed const &	max(Fixed const & lhs, Fixed const & rhs)
{
	return (lhs >= rhs ? lhs : rhs);
}
