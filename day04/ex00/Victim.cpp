/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:06:02 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/11 00:09:23 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(void)
{
	std::cout << "Some random victim called " << this->name << " just popped !" << std::endl;
}

Victim::Victim(std::string name) : name(name)
{
	std::cout << "Some random victim called " << this->name << " just popped !" << std::endl;
}

Victim::Victim(Victim const &src)
{
	*this = src;
	std::cout << "Some random victim called " << this->name << " just popped !" << std::endl;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->name << " just died for no apparent reason !" << std::endl;

}

Victim const	&Victim::operator=(Victim const &rhs)
{
	if (this != &rhs)
		this->name = rhs.name;
	return (*this);
}

std::string		Victim::get_name(void) const
{
	return (this->name);
}

void			Victim::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Victim const &rhs)
{
	o << "I'm " << rhs.get_name() << " and I like otters !" << std::endl;
	return (o);
}
