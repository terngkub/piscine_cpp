/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:49:51 by                   #+#    #+#             */
/*   Updated: 2019/01/13 14:51:41 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"
#include "Move.hpp"

Input::Input( void ) :
	key(getch()) {

	return;
}

Input::~Input( void ) {

	return;
}

Input::Input(Input const & src) {

	*this = src;
	return;
}

Input & Input::operator=(Input const & rhs)
{
	key = rhs.key;
	return *this;
}

bool Input::is_error( void ) const
{
	return key == ERR;
}

bool Input::is_exit( void ) const
{
	return key == 'q';
}

bool Input::is_fire( void ) const
{
	return key == ' ';
}

Move Input::get_move( void ) const
{
	if (key == KEY_UP)
		return Move(0, -1);
	else if (key == KEY_DOWN)
		return Move(0, 1);
	else if (key == KEY_LEFT)
		return Move(-1, 0);
	else if (key == KEY_RIGHT)
		return Move(1, 0);
	return Move();
}
