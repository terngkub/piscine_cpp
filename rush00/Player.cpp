/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:57:23 by                   #+#    #+#             */
/*   Updated: 2019/01/12 23:34:15 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "IInput.hpp"
#include "Bullet.hpp"
#include "Position.hpp"
#include <cstddef>

Player::~Player( void ) {

	return;
}

Player::Player( int width, int height) :
	AGameEntity(Position(1, height / 2)),
	max_height(height),
	max_width(width) {

	return;
}

IGameEntity * Player::update( void ) {

	IGameEntity	*obj = nullptr;
	if (input != nullptr)
	{
		if (input->is_fire())
			obj =  shoot_bullet();
		else
		{
			update_position(input->get_move());
			obj = nullptr;
		}
		input = nullptr;
	}
	return obj;

}

void Player::take_command(IInput const & cmd) {

	input = &cmd;
}

void	Player::update_position( Move const & move) {

	int new_x = coordinates.x + move.getX();
	int new_y = coordinates.y + move.getY();
	if (new_x > 0 && new_x < max_width - 1)
		coordinates.x += move.getX();
	if (new_y > 0 && new_y < max_height - 1)
		coordinates.y += move.getY();
}

Bullet	* Player::shoot_bullet( void ) const {
	Position bullet_position = coordinates;
	bullet_position.x += 1;
	Bullet *bullet = new Bullet(bullet_position);
	return bullet;
}

char	Player::get_char_sign( void ) const {

	return 'o';
}
