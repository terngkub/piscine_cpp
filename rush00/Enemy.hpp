/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:14:53 by                   #+#    #+#             */
/*   Updated: 2019/01/12 20:14:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "AGameEntity.hpp"

class Enemy : public AGameEntity
{
	public:

		Enemy( void );
		Enemy(int x, int y);
		~Enemy( void );
		char	get_char_sign( void ) const;

	private:

		Enemy( Enemy const & src );
		Enemy & operator=( Enemy const & rhs );
};

#endif
