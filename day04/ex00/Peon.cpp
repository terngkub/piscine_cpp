/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 23:49:58 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/11 00:09:32 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(void) : Victim()
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &src) : Victim(src)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

void			Peon::getPolymorphed(void) const
{
	std::cout << this->get_name() << " has bee turned into a pink pony !" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Peon const &rhs)
{
	std::cout << "I'm " << rhs.get_name() << " and I like otters !" << std::endl;
	return (o);
}
