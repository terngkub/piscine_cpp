/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CrapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:23:13 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/08 19:17:55 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRAPTRAP_H
# define CRAPTRAP_H

# include <iostream>

class CrapTrap
{
	public:
		CrapTrap(void);
		CrapTrap(std::string name);
		CrapTrap(CrapTrap const &src);
		~CrapTrap(void);

		CrapTrap	&operator=(CrapTrap const &rhs);

		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		// Getter
		std::string	get_name(void) const;
		int			get_hit_points(void) const;
		int			get_max_hit_points(void) const;
		int			get_energy_points(void) const;
		int			get_max_energy_points(void) const;
		int			get_level(void) const;
		int			get_melee_attack_damage(void) const;
		int			get_ranged_attack_damage(void) const;
		int			get_armor_damage_reduction(void) const;
		
	protected:
		std::string	name;
		int			hit_points;
		int			max_hit_points;
		int			energy_points;
		int			max_energy_points;
		int			level;
		int			melee_attack_damage;
		int			ranged_attack_damage;
		int			armor_damage_reduction;
};

std::ostream		&operator<<(std::ostream &o, CrapTrap const &rhs);

#endif
