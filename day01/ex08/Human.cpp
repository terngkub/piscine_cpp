/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 20:51:21 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/04 22:05:22 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void	Human::meleeAttack(std::string const & target)
{
	std::cout << "Melee attack to " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target)
{
	std::cout << "Ranged attack to " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << "Intimidating shout to " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target)
{

	std::map<std::string, t_action>	action_ptr;
	action_ptr.insert(t_action_pair("meleeAttack", &Human::meleeAttack));
	action_ptr.insert(t_action_pair("rangedAttack", &Human::rangedAttack));
	action_ptr.insert(t_action_pair("intimidatingShout", &Human::intimidatingShout));

	if (action_ptr.find(action_name) != action_ptr.end())
		(this->*action_ptr[action_name])(target);
	else
		std::cout << "No action found" << std::endl;
}
