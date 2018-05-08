/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:21:10 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/08 14:40:58 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	a;
	FragTrap	b("B");
	FragTrap	c;

	c = a;
	a.rangedAttack("enemy1");
	a.meleeAttack("enemy2");
	a.takeDamage(50);
	a.takeDamage(30);
	a.takeDamage(10);
	a.beRepaired(110);
	a.vaulthunter_dot_exe("enemy3");
	a.vaulthunter_dot_exe("enemy4");
	return (0);
}
