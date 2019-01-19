/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:49:54 by                   #+#    #+#             */
/*   Updated: 2019/01/13 14:52:24 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HPP
# define INPUT_HPP
# include <ncurses.h>
# include "IInput.hpp"
# include "Move.hpp"

class Input : public IInput
{
	public:
		Input();
		~Input();
		Input(Input const & src);
		Input & operator=(Input const & rhs);

		bool	is_error( void ) const;
		bool	is_exit( void ) const;
		bool	is_fire( void ) const;
		Move	get_move( void ) const;

	private:
		int key;
};

#endif
