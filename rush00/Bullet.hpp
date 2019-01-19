/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:29:29 by                   #+#    #+#             */
/*   Updated: 2019/01/13 21:40:07 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP
# include "AGameEntity.hpp"

class Bullet : public AGameEntity {

	public:
		Bullet( Position const & starting_position );
		virtual ~Bullet( void );
		char			get_char_sign( void ) const;

	private:
		Bullet( void );
		Bullet( Bullet const & );
		Bullet & operator=( Bullet const & );
};

#endif // BULLET_HPP
