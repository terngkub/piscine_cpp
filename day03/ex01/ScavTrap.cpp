/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:31:20 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/08 16:46:16 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) :
	hit_points(100),
	max_hit_points(100),
	energy_points(50),
	max_energy_points(50),
	level(1),
	name("Default"),
	melee_attack_damage(20),
	ranged_attack_damage(15),
	armor_damage_reduction(3)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) :
	hit_points(100),
	max_hit_points(100),
	energy_points(50),
	max_energy_points(50),
	level(1),
	name(name),
	melee_attack_damage(20),
	ranged_attack_damage(15),
	armor_damage_reduction(3)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
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

void		ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "ScavTrap ";
	std::cout << this->name;
	std::cout << " attacks ";
	std::cout << target;
	std::cout << " at range, causing ";
	std::cout << this->ranged_attack_damage;
	std::cout << " points of damage !";
	std::cout << std::endl;
}

void		ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "ScavTrap ";
	std::cout << this->name;
	std::cout << " attacks ";
	std::cout << target;
	std::cout << " at melee, causing ";
	std::cout << this->melee_attack_damage;
	std::cout << " points of damage !";
	std::cout << std::endl;
}

void		ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points - ((int)amount - this->armor_damage_reduction) < 0)
		this->hit_points = 0;
	else
		this->hit_points -= (amount - this->armor_damage_reduction);

	std::cout << "ScavTrap ";
	std::cout << this->name;
	std::cout << " takes damage of ";
	std::cout << amount;
	std::cout << ", hit points left ";
	std::cout << this->hit_points;
	std::cout << ".";
	std::cout << std::endl;
}

void		ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points + amount > this->max_hit_points)
		this->hit_points = this->max_hit_points;
	else
		this->hit_points += amount;

	std::cout << "ScavTrap ";
	std::cout << this->name;
	std::cout << " is repaired by ";
	std::cout << amount;
	std::cout << ", hit points left ";
	std::cout << this->hit_points;
	std::cout << ".";
	std::cout << std::endl;
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


// Getter

std::string	ScavTrap::get_name(void) const
{
	return (this->name);
}

int				ScavTrap::get_hit_points(void) const
{
	return (this->hit_points);
}

int				ScavTrap::get_max_hit_points(void) const
{
	return (this->max_hit_points);
}

int				ScavTrap::get_energy_points(void) const
{
	return (this->energy_points);
}

int				ScavTrap::get_max_energy_points(void) const
{
	return (this->max_energy_points);
}

int				ScavTrap::get_level(void) const
{
	return (this->level);
}

int				ScavTrap::get_melee_attack_damage(void) const
{
	return (this->melee_attack_damage);
}

int				ScavTrap::get_ranged_attack_damage(void) const
{
	return (this->ranged_attack_damage);
}

int				ScavTrap::get_armor_damage_reduction(void) const
{
	return (this->armor_damage_reduction);
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
