/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:21:10 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/08 16:35:38 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

static void	usage(void)
{
	std::cout << "usage: ./a.out [fragtrap|scavtrap]" << std::endl;
	exit(1);
}

static void	fragtrap(void)
{
	std::cout << "******* FragTrap Test *******" << std::endl << std::endl;

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
}

static void	scavtrap(void)
{
	std::cout << "******* ScavTrap Test *******" << std::endl << std::endl;
	
	// Constructors
	std::cout << std::endl << "Constructors test" << std::endl;
	std::cout << "-------------------------------------" << std::endl << std::endl;

	ScavTrap	a;
	ScavTrap	b("B");
	ScavTrap	c;

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

	// Challenge newcommer
	std::cout << std::endl << "ChallengeNewcomer test" << std::endl;
	std::cout << "-------------------------------------" << std::endl << std::endl;

	a.challengeNewcommer();
	a.challengeNewcommer();
	a.challengeNewcommer();

	// Deconstructors
	std::cout << std::endl << "Deconstructor test" << std::endl;
	std::cout << "-------------------------------------" << std::endl << std::endl;
}

int	main(int argc, char **argv)
{
	std::string	test;

	if (argc != 2)
		usage();

	test = argv[1];
	if (test.compare("fragtrap") == 0)
		fragtrap();
	else if (test.compare("scavtrap") == 0)
		scavtrap();
	else
		usage();

	return (0);
}
