/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:56:24 by                   #+#    #+#             */
/*   Updated: 2019/01/12 23:33:57 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP
# include "AGameEntity.hpp"
# include "Position.hpp"
# include "Bullet.hpp"
# include "IInput.hpp"

class Player : public AGameEntity {

	public:

		virtual ~Player( void );
		Player( int width, int height);
		void	take_command(IInput const &);
		IGameEntity *	update( void );
		char			get_char_sign( void ) const;


	private:
		Player( void );
		Player( Player const & );
		Player & operator=( Player const & );

		static Position const	starting_position;

		void update_position( Move const & move);
		Bullet *	 shoot_bullet( void ) const;

		int	const		max_height;
		int	const		max_width;
		IInput const *	input;
};

#endif // PLAYER_HPP
