/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:44:29 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/01 17:50:52 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string type) : type(type) {}

std::string&	Weapon::getType(void)
{
	std::string& ref = this->type;
	return ref;
}

void			Weapon::setType(std::string type)
{
	this->type = type;
}
