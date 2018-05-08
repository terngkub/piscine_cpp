/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:31:20 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/08 14:40:21 by nkamolba         ###   ########.fr       */
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
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "Name constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		/*
		this->hit_points = rhs.hit_points;
		this->max_hit_points = rhs.max_hit_points;
		this->energy_points = rhs.energy_points;
		this->max_energy_points = rhs.max_energy_points;
		this->level = rhs.level;
		this->name = rhs.name;
		this->melee_attack_damage = rhs.melee_attack_damage;
		this->ranged_attack_damage = rhs.ranged_attack_damage;
		this->armor_damage_reductions =  rhs.armor_damage_reductions;
		*/
	}
	return *this;
}

void		FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP ";
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
	std::cout << "FR4G-TP ";
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
	if (this->hit_points - amount <= 0)
		this->hit_points = 0;
	else
		this->hit_points -= amount;

	std::cout << "FR4G-TP ";
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
	if (this->hit_points + amount >= this->max_hit_points)
		this->hit_points = this->max_hit_points;
	else
		this->hit_points += amount;

	std::cout << "FR4G-TP ";
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
		"stealing his/her money",
		"ignoring him/her"
	};

	if (this->energy_points < 25)
	{
		std::cout << "FR4G-TP tries to use vaulthunter_dot_exe but doesn't have enough energy." << std::endl;
	}
	else
	{
		std::cout << "FR4G-TP ";
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
