/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGameEntity.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:37:54 by                   #+#    #+#             */
/*   Updated: 2019/01/13 20:46:33 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGAMEENTITY_HPP
# define AGAMEENTITY_HPP

# include "IGameEntity.hpp"
# include "Position.hpp"
# include "Move.hpp"

class AGameEntity : public IGameEntity {

	public:

		virtual 			~AGameEntity( void );
		void				update_position( Move const & );
		virtual IGameEntity	*update( void );
		Position const &	get_position( void ) const;
		Move const &		get_move( void ) const;
		bool				is_destroyed( void ) const;
		virtual void		collides_with( IGameEntity & );
		virtual	void		take_damage( int );
		void				kill( void );

	protected:

		AGameEntity( Position const &, Move const & = Move() );
		Position	coordinates;
		Move		default_move;

	private:

		AGameEntity( void );
		AGameEntity( AGameEntity const & );
		AGameEntity & operator=( AGameEntity const & );

		bool	destroyed;

};

#endif // AGAMEENTITY_HPP
