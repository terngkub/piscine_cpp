/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 00:35:30 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/09 00:46:03 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap()
{
	std::cout << "NinjaTrap default constructor called" << std::endl;

	this->hit_points = 60;
	this->max_hit_points = 60;
	this->energy_points = 120;
	this->max_energy_points = 120;
	this->level = 1;
	this->melee_attack_damage = 60;
	this->ranged_attack_damage = 5;
	this->armor_damage_reduction = 0;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	std::cout << "NinjaTrap name constructor called" << std::endl;

	this->hit_points = 60;
	this->max_hit_points = 60;
	this->energy_points = 120;
	this->max_energy_points = 120;
	this->level = 1;
	this->melee_attack_damage = 60;
	this->ranged_attack_damage = 5;
	this->armor_damage_reduction = 0;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) : ClapTrap(src)
{
	std::cout << "NinjaTrap copy constructor called" << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NinjaTrap destructor called" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap const &trap) const
{
	std::cout << "ClapTrap "
		<< trap.get_name()
		<< "was shoeboxing (???) by ninja."
		<< std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap const &trap) const
{
	std::cout << "FragTrap "
		<< trap.get_name()
		<< "was shoeboxing (???) by ninja."
		<< std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap const &trap) const
{
	std::cout << "ScavTrap "
		<< trap.get_name()
		<< "was shoeboxing (???) by ninja."
		<< std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap const &trap) const
{
	std::cout << "NinjaTrap "
		<< trap.get_name()
		<< "was shoeboxing (???) by ninja."
		<< std::endl;
}
