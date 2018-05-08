/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:21:10 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/08 15:46:15 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	// Constructors
	std::cout << std::endl << "Constructors test" << std::endl;
	std::cout << "-------------------------------------" << std::endl << std::endl;

	FragTrap	a;
	FragTrap	b("B");
	FragTrap	c;

	c = b;

	std::cout << std::endl;
	std::cout << a << std::endl << std::endl;
	std::cout << b << std::endl << std::endl;
	std::cout << c << std::endl << std::endl;

	// Attacks
	std::cout << std::endl << "Attacks test" << std::endl;
	std::cout << "-------------------------------------" << std::endl << std::endl;

	a.rangedAttack("enemy1");
	a.meleeAttack("enemy2");

	// Take damage & be repaired
	std::cout << std::endl <<  "Take damage & repair test" << std::endl;
	std::cout << "-------------------------------------" << std::endl << std::endl;

	a.takeDamage(30);
	std::cout << "Hit points: " << a.get_hit_points() << std::endl;
	a.takeDamage(80);
	std::cout << "Hit points: " << a.get_hit_points() << std::endl;
	a.takeDamage(10);
	std::cout << "Hit points: " << a.get_hit_points() << std::endl;
	a.beRepaired(20);
	std::cout << "Hit points: " << a.get_hit_points() << std::endl;
	a.beRepaired(110);
	std::cout << "Hit points: " << a.get_hit_points() << std::endl;

	// Vaulthunter_dot_exe
	std::cout << std::endl << "Vaulthunter_dot_exe test" << std::endl;
	std::cout << "-------------------------------------" << std::endl << std::endl;

	a.vaulthunter_dot_exe("enemy3");
	std::cout << "Energy points: " << a.get_energy_points() << std::endl;
	a.vaulthunter_dot_exe("enemy4");
	std::cout << "Energy points: " << a.get_energy_points() << std::endl;
	a.vaulthunter_dot_exe("enemy5");
	std::cout << "Energy points: " << a.get_energy_points() << std::endl;
	a.vaulthunter_dot_exe("enemy6");
	std::cout << "Energy points: " << a.get_energy_points() << std::endl;
	a.vaulthunter_dot_exe("enemy7");
	std::cout << "Energy points: " << a.get_energy_points() << std::endl;
	
	// Deconstructors
	std::cout << std::endl << "Deconstructor test" << std::endl;
	std::cout << "-------------------------------------" << std::endl << std::endl;

	return (0);
}
