/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:15:24 by                   #+#    #+#             */
/*   Updated: 2019/01/13 20:38:30 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include <cstdlib>

Enemy::Enemy( void ) :
	AGameEntity(
			Position(60, rand()%20),
			Move(-1, 0)) {
	return;
}

Enemy::Enemy(int x, int y) :
	AGameEntity(Position(x - 1, y), Move(-1, 0))
{

	return;
}

Enemy::~Enemy( void ) {

	return;
}

char	Enemy::get_char_sign( void ) const {

	return '#';
}
