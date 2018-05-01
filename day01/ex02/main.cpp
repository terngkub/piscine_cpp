/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:36:40 by terng             #+#    #+#             */
/*   Updated: 2018/05/01 16:23:50 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int	main(void)
{
	ZombieEvent	ze1;
	ZombieEvent ze2;
	Zombie*		zombies[5];

	ze1.setZombieType("Walker");
	ze2.setZombieType("Runner");
	
	zombies[0] = ze1.newZombie("First");
	zombies[1] = ze2.newZombie("Second");
	zombies[2] = new Zombie("Third", "Necromancer");
	zombies[3] = ze1.randomChump();
	zombies[4] = ze2.randomChump();

	for (int i = 0; i < 5; i++)
		zombies[i]->announce();
	
	for (int i = 0; i < 5; i++)
		delete zombies[i];

	return (0);
}



	

