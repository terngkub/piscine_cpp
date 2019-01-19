/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:34:29 by                   #+#    #+#             */
/*   Updated: 2019/01/12 12:34:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Move.hpp"

Move::Move( void ) : x(0), y(0) {

	return;
}

Move::Move( int x, int y ) : x(x), y(y) {

	return;
}

Move::Move( Move const & rhs ) {

	*this = rhs;

	return;
}

Move::~Move( void ) {

	return;
}

Move &	Move::operator=(Move const & rhs) {

	x = rhs.x;
	y = rhs.y;
	return *this;
}

int	Move::getX( void ) const {

	return x;
}

int	Move::getY( void ) const {

	return y;
}
