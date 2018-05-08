/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:31:20 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/09 00:47:55 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;

	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 50;
	this->max_energy_points = 50;
	this->level = 1;
	this->melee_attack_damage = 20;
	this->ranged_attack_damage = 15;
	this->armor_damage_reduction = 3;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;

	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 50;
	this->max_energy_points = 50;
	this->level = 1;
	this->melee_attack_damage = 20;
	this->ranged_attack_damage = 15;
	this->armor_damage_reduction = 3;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void		ScavTrap::challengeNewcommer(void)
{
	std::string challenge[5] = {
		"SHOOT !!!",
		"DANCE !!!",
		"SLEEP !!!",
		"OMG !!!",
		"GO AWAY !!!"
	};

	std::cout << "ScavTrap ";
	std::cout << this->name;
	std::cout << ": ";
	std::cout << challenge[rand() % 5];
	std::cout << std::endl;
}

std::ostream	&operator<<(std::ostream &o, ScavTrap const &rhs)
{
	o << "ScavTrap" << std::endl;
	o << "Name: " << rhs.get_name() << std::endl;
	o << "Hit points: " << rhs.get_hit_points() << std::endl;
	o << "Max hit points: " << rhs.get_max_hit_points() << std::endl;
	o << "Energy points: " << rhs.get_energy_points() << std::endl;
	o << "Max energy points: " << rhs.get_max_energy_points() << std::endl;
	o << "Level: " << rhs.get_level() << std::endl;
	o << "Melee attack damage: " << rhs.get_melee_attack_damage() << std::endl;
	o << "Ranged attack damage: " << rhs.get_ranged_attack_damage() << std::endl;
	o << "Armor damage reduction: " << rhs.get_armor_damage_reduction();
	return (o);
}
