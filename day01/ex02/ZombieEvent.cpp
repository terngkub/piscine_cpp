/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:28:32 by terng             #+#    #+#             */
/*   Updated: 2018/04/26 16:11:12 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
	std::cout << "A ZombieEvent is created." << std::endl;
}

ZombieEvent::~ZombieEvent(void)
{
	std::cout << "A ZombieEvent is destroyed." << std::endl;
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie*	ZombieEvent::newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name, this->type);
	return zombie;
}

Zombie*	ZombieEvent::randomChump()
{
	std::string	names[10] = {
		"AAA", "BBB", "CCC", "DDD", "EEE", "FFF", "GGG", "HHH", "III", "JJJ"};

	Zombie *zombie = new Zombie(names[rand() % 10], this->type);
	return zombie;
}

