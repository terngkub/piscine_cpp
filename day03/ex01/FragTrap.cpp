/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:31:20 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/08 16:03:01 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : hit_points(100),
	max_hit_points(100),
	energy_points(100),
	max_energy_points(100),
	level(1),
	name("Default"),
	melee_attack_damage(30),
	ranged_attack_damage(20),
	armor_damage_reduction(5)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) :
	hit_points(100),
	max_hit_points(100),
	energy_points(100),
	max_energy_points(100),
	level(1),
	name(name),
	melee_attack_damage(30),
	ranged_attack_damage(20),
	armor_damage_reduction(5)
{
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->hit_points = rhs.hit_points;
		this->max_hit_points = rhs.max_hit_points;
		this->energy_points = rhs.energy_points;
		this->max_energy_points = rhs.max_energy_points;
		this->level = rhs.level;
		this->name = rhs.name;
		this->melee_attack_damage = rhs.melee_attack_damage;
		this->ranged_attack_damage = rhs.ranged_attack_damage;
		this->armor_damage_reduction =  rhs.armor_damage_reduction;
	}
	return *this;
}

void		FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FragTrap ";
	std::cout << this->name;
	std::cout << " attacks ";
	std::cout << target;
	std::cout << " at range, causing ";
	std::cout << this->ranged_attack_damage;
	std::cout << " points of damage !";
	std::cout << std::endl;
}

void		FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FragTrap ";
	std::cout << this->name;
	std::cout << " attacks ";
	std::cout << target;
	std::cout << " at melee, causing ";
	std::cout << this->melee_attack_damage;
	std::cout << " points of damage !";
	std::cout << std::endl;
}

void		FragTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points - ((int)amount - this->armor_damage_reduction) < 0)
		this->hit_points = 0;
	else
		this->hit_points -= (amount - this->armor_damage_reduction);

	std::cout << "FragTrap ";
	std::cout << this->name;
	std::cout << " takes damage of ";
	std::cout << amount;
	std::cout << ", hit points left ";
	std::cout << this->hit_points;
	std::cout << ".";
	std::cout << std::endl;
}

void		FragTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points + amount > this->max_hit_points)
		this->hit_points = this->max_hit_points;
	else
		this->hit_points += amount;

	std::cout << "FragTrap ";
	std::cout << this->name;
	std::cout << " is repaired by ";
	std::cout << amount;
	std::cout << ", hit points left ";
	std::cout << this->hit_points;
	std::cout << ".";
	std::cout << std::endl;
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

std::string		FragTrap::get_name(void) const
{
	return (this->name);
}

int				FragTrap::get_hit_points(void) const
{
	return (this->hit_points);
}

int				FragTrap::get_max_hit_points(void) const
{
	return (this->max_hit_points);
}

int				FragTrap::get_energy_points(void) const
{
	return (this->energy_points);
}

int				FragTrap::get_max_energy_points(void) const
{
	return (this->max_energy_points);
}

int				FragTrap::get_level(void) const
{
	return (this->level);
}

int				FragTrap::get_melee_attack_damage(void) const
{
	return (this->melee_attack_damage);
}

int				FragTrap::get_ranged_attack_damage(void) const
{
	return (this->ranged_attack_damage);
}

int				FragTrap::get_armor_damage_reduction(void) const
{
	return (this->armor_damage_reduction);
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
