/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:04:16 by terng             #+#    #+#             */
/*   Updated: 2018/04/26 16:09:56 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type)
{
	this->name = name;
	this->type = type;
	std::cout << "<" << this->name << " (" << this->type << ")> has born." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "<" << this->name << " (" << this->type << ")> died." << std::endl;
}

void	Zombie::annouce(void)
{
	std::cout << "<" << this->name << " (" << this->type << ")> Brainnnsss..." << std::endl;
}
