/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:35:13 by terng             #+#    #+#             */
/*   Updated: 2018/04/26 11:45:46 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name)
{
	this->name = name;
	std::cout << "Pony " << this->name << " is born." << std::endl;
}

Pony::~Pony(void)
{
	std::cout << "Pony " << this->name << " died." << std::endl;
}

void	Pony::getName(void)
{
	std::cout << "My name is " << this->name << std::endl;
}
