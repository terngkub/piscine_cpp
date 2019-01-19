/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:23:37 by                   #+#    #+#             */
/*   Updated: 2019/01/12 11:23:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_HPP
# define MOVE_HPP

class Move {

	public:

		Move( void );
		Move( int x, int y );
		Move( Move const & );
		~Move( void );
		Move & operator=( Move const & );

		int	getX( void ) const;
		int	getY( void ) const;

	private:

		int	x;
		int	y;
};

#endif // MOVE_HPP
