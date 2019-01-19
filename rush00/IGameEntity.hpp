/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGameEntity.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:33:51 by                   #+#    #+#             */
/*   Updated: 2019/01/12 15:21:16 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGAMEENTITY_HPP
# define IGAMEENTITY_HPP
# include "Move.hpp"
# include "Position.hpp"

class IGameEntity {

	public:
		virtual ~IGameEntity( void ) { }

		virtual	void				update_position( Move const & ) = 0;
		virtual IGameEntity	*		update( void ) = 0;
		virtual	Position const &	get_position( void ) const = 0;
		virtual Move const &		get_move( void ) const = 0;
		virtual char				get_char_sign ( void ) const = 0;

		virtual	bool				is_destroyed( void ) const = 0;
		virtual void				collides_with( IGameEntity & ) = 0;
		virtual	void				take_damage( int ) = 0;
		virtual void				kill( void ) = 0;

};

#endif // IGAMEENTITY_HPP
