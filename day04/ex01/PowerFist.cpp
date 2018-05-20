/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:13:11 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/20 19:13:59 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(PowerFist const & src)
{
	*this = src;
}

PowerFist::~PowerFist()
{
}

PowerFist & PowerFist::operator=(PowerFist const & rhs)
{
	if (this != &rhs)
		AWeapon::operator=(rhs);
	return *this;
}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
