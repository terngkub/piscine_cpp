/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:31:20 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/08 19:17:30 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : CrapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;

	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 100;
	this->max_energy_points = 100;
	this->level = 1;
	this->melee_attack_damage = 30;
	this->ranged_attack_damage = 20;
	this->armor_damage_reduction = 5;
}

FragTrap::FragTrap(std::string name) : CrapTrap(name)
{
	std::cout << "FragTrap name constructor called" << std::endl;

	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 100;
	this->max_energy_points = 100;
	this->level = 1;
	this->melee_attack_damage = 30;
	this->ranged_attack_damage = 20;
	this->armor_damage_reduction = 5;
}

FragTrap::FragTrap(FragTrap const &src) : CrapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void		FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	std::string	attack[5] = {
		"shooting",
		"dancing",
		"sleeping",
		"stealing money",
		"ignoring"
	};

	if (this->energy_points < 25)
	{
		std::cout << "FragTrap tries to use vaulthunter_dot_exe but doesn't have enough energy." << std::endl;
	}
	else
	{
		std::cout << "FragTrap ";
		std::cout << this->name;
		std::cout << " attacks ";
		std::cout << target;
		std::cout << " by ";
		std::cout << attack[rand() % 5];
		std::cout << " !";
		std::cout << std::endl;
		this->energy_points -= 25;
	}
}

std::ostream	&operator<<(std::ostream &o, FragTrap const &rhs)
{
	o << "FragTrap" << std::endl;
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
