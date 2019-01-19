/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:51:44 by                   #+#    #+#             */
/*   Updated: 2019/01/12 16:54:32 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Position.hpp"

Position::Position( void ) : x(0), y(0) {

	return;
}

Position::Position( Position const & rhs ) {

	*this = rhs;

	return;
}

Position::~Position( void ) {

	return;
}

Position::Position( int x, int y) :
	x(x),
	y(y) {

	return;
}

Position &	Position::operator=(Position const & rhs) {

	x = rhs.x;
	y = rhs.y;
	return *this;
}

bool Position::operator==( Position const & rhs ) const
{
	return (x == rhs.x && y == rhs.y);
}