/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGameEntity.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:25:32 by                   #+#    #+#             */
/*   Updated: 2019/01/12 11:25:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Position.hpp"
#include "Move.hpp"
#include "AGameEntity.hpp"
#include "IGameEntity.hpp"
#include <cstddef>

AGameEntity::AGameEntity( Position const & position,
		Move const & move ) :
	coordinates(position),
	default_move(move),
	destroyed(false) {

	return;
}

AGameEntity::~AGameEntity( void ) {

	return;
}

void	AGameEntity::update_position( Move const & move) {

	coordinates.x += move.getX();
	coordinates.y += move.getY();
}

Position const & AGameEntity::get_position( void ) const {

	return coordinates;
}

IGameEntity	*AGameEntity::update( void ) {

	update_position(default_move);
	return nullptr;
}

bool	AGameEntity::is_destroyed( void ) const {

	return destroyed;
}

void	AGameEntity::collides_with( IGameEntity & object) {

	take_damage(0);
	object.take_damage(0);
}

void	AGameEntity::take_damage( int __attribute__((unused))dmg ) {

	kill();
}

void	AGameEntity::kill( void ) {

	destroyed = true;
}

Move const &	AGameEntity::get_move( void ) const {

	return default_move;
}
