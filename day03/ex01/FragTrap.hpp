/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:23:13 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/08 15:30:25 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <iostream>

class FragTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		FragTrap	&operator=(FragTrap const &rhs);

		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		vaulthunter_dot_exe(std::string const &target);

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
		
	private:
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

std::ostream		&operator<<(std::ostream &o, FragTrap const &rhs);

#endif
