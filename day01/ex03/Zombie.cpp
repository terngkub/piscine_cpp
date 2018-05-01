/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:04:16 by terng             #+#    #+#             */
/*   Updated: 2018/05/01 16:18:47 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "An unnammed zombie with a default type of walker whas born." << std::endl;
}

Zombie::Zombie(std::string name, std::string type) : name(name), type(type)
{
	std::cout << "<" << this->name << " (" << this->type << ")> has born." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "<" << this->name << " (" << this->type << ")> died." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::set_type(std::string type)
{
	this->type = type;
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->name << " (" << this->type << ")> Brainnnsss..." << std::endl;
}
