/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:19:06 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/20 18:28:42 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy
{
	public:
		Enemy();
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & src);
		~Enemy();

		Enemy & operator=(Enemy const & rhs);

		int				getHP() const;
		std::string		getType() const; 
		void			setHP(int hp);

		virtual void	takeDamage(int damage) = 0;
	
	private:
		int				_hp;
		std::string		_type;
};

std::ostream & operator<<(std::ostream & o, Enemy const &rhs);

#endif
