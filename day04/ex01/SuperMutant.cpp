/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:29:17 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/20 18:37:33 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & src)
{
	*this = src;
	std::cout << "Gaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ...";
}

SuperMutant & SuperMutant::operator=(SuperMutant const & rhs)
{
	if (this != &rhs)
		Enemy::operator=(rhs);
	return *this;
}

void	SuperMutant::takeDamage(int damage)
{
	int hp = getHP() - damage + 3;
	setHP(hp > 0 ? hp : 0);
}
