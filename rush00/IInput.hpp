/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IInput.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:13:05 by                   #+#    #+#             */
/*   Updated: 2019/01/12 14:04:53 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IINPUT_HPP
# define IINPUT_HPP
# include "Move.hpp"

class IInput {

	public:
		~IInput( void ) {}
		virtual bool	is_exit( void ) const = 0;
		virtual	bool	is_fire( void ) const = 0;
		virtual Move	get_move( void ) const = 0;

};

#endif // IINPUT_HPP
