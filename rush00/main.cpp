/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:41:41 by                   #+#    #+#             */
/*   Updated: 2019/01/13 21:13:09 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Input.hpp"

int	main( void ) {

	Game	game(60, 20);
	Input	input;

	while (!game.is_over()) {
		if (!game.has_input)
		{
			input = Input();
			if (!input.is_error())
				game.has_input = true;
		}
		if (game.should_update())
		{
			game.update(input);
			game.render();
		}
	}

	return 0;
}
