/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:13:37 by                   #+#    #+#             */
/*   Updated: 2019/01/12 19:13:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"
#include "Move.hpp"
#include "Position.hpp"

Bullet::Bullet( Position const & starting_position ) :
	AGameEntity(starting_position, Move(1, 0)) {
}

Bullet::~Bullet( void ) {

	return;
}

char	Bullet::get_char_sign( void ) const {

	return '-';
}
