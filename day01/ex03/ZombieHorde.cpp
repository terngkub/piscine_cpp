/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:55:56 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/01 16:21:46 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	std::string	names[5] = {"AAA", "BBB", "CCC", "DDD", "EEE"};
	
	this->zombies = new Zombie[N];
	this->size = N;
	
	for (int i = 0; i < N; i++)
		this->zombies[i].set_name(names[rand() % 5]);
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->zombies;
}

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < this->size; i++)
		this->zombies[i].announce();
}
