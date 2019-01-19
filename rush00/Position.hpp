/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:51:27 by                   #+#    #+#             */
/*   Updated: 2019/01/12 16:53:25 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_HPP
# define POSITION_HPP

class Position {

	public:

		Position( void );
		Position( Position const & );
		~Position( void );
		Position & operator=( Position const & );

		bool operator==( Position const & rhs ) const;

		Position( int x, int y);

		 int	x;
		 int	y;
};

#endif // POSITION_HPP
