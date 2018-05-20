/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:41:29 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/20 19:04:20 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	public:
		Character();
		Character(std::string const & name);
		Character(Character const & src);
		~Character();

		Character & operator=(Character const & rhs);

		void		recoverAP();
		void		equip(AWeapon *weapon);
		void		attack(Enemy *enemy);

		std::string	getName() const;
		int			getAP() const;
		AWeapon		*getWeapon() const;

	private:
		std::string	_name;
		int			_ap;
		AWeapon		*_weapon;
};

std::ostream & operator<<(std::ostream & o, Character const & rhs);

#endif
