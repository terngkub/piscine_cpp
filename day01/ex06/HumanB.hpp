/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:14:07 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/01 18:31:54 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	public:
		
		HumanB(std::string name);

		void		setWeapon(Weapon& weapon);
		void		attack(void);

	private:
		
		std::string	name;
		Weapon*		weapon;
};

#endif
