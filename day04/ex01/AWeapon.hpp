/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 11:08:15 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/20 11:52:19 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon
{
	public:
		AWeapon();
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const & src);
		~AWeapon();

		AWeapon & operator=(AWeapon const & rhs);
		
		std::string		getName() const;
		int				getAPCost() const;
		int				getDamage() const;

		virtual void	attack() const = 0;

	private:
		std::string		_name;
		int				_apcost;
		int				_damage;
};

std::ostream & operator<<(std::ostream & o, AWeapon const & rhs);

#endif
