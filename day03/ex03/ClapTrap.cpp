/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:31:20 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/09 00:47:12 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
	hit_points(100),
	max_hit_points(100),
	energy_points(100),
	max_energy_points(100),
	level(1),
	name("Default"),
	melee_attack_damage(30),
	ranged_attack_damage(20),
	armor_damage_reduction(5)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
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
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
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

void		ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << "ClapTrap ";
	std::cout << this->name;
	std::cout << " attacks ";
	std::cout << target;
	std::cout << " at range, causing ";
	std::cout << this->ranged_attack_damage;
	std::cout << " points of damage !";
	std::cout << std::endl;
}

void		ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << "ClapTrap ";
	std::cout << this->name;
	std::cout << " attacks ";
	std::cout << target;
	std::cout << " at melee, causing ";
	std::cout << this->melee_attack_damage;
	std::cout << " points of damage !";
	std::cout << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points - ((int)amount - this->armor_damage_reduction) < 0)
		this->hit_points = 0;
	else
		this->hit_points -= (amount - this->armor_damage_reduction);

	std::cout << "ClapTrap ";
	std::cout << this->name;
	std::cout << " takes damage of ";
	std::cout << amount;
	std::cout << ", hit points left ";
	std::cout << this->hit_points;
	std::cout << ".";
	std::cout << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points + amount > this->max_hit_points)
		this->hit_points = this->max_hit_points;
	else
		this->hit_points += amount;

	std::cout << "ClapTrap ";
	std::cout << this->name;
	std::cout << " is repaired by ";
	std::cout << amount;
	std::cout << ", hit points left ";
	std::cout << this->hit_points;
	std::cout << ".";
	std::cout << std::endl;
}

std::string		ClapTrap::get_name(void) const
{
	return (this->name);
}

int				ClapTrap::get_hit_points(void) const
{
	return (this->hit_points);
}

int				ClapTrap::get_max_hit_points(void) const
{
	return (this->max_hit_points);
}

int				ClapTrap::get_energy_points(void) const
{
	return (this->energy_points);
}

int				ClapTrap::get_max_energy_points(void) const
{
	return (this->max_energy_points);
}

int				ClapTrap::get_level(void) const
{
	return (this->level);
}

int				ClapTrap::get_melee_attack_damage(void) const
{
	return (this->melee_attack_damage);
}

int				ClapTrap::get_ranged_attack_damage(void) const
{
	return (this->ranged_attack_damage);
}

int				ClapTrap::get_armor_damage_reduction(void) const
{
	return (this->armor_damage_reduction);
}

std::ostream	&operator<<(std::ostream &o, ClapTrap const &rhs)
{
	o << "ClapTrap" << std::endl;
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
