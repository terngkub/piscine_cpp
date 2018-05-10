/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:14:17 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/11 00:07:35 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void) : name("NAME"), title("TITLE")
{
	std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(std::string name, std::string title) : name(name), title(title)
{
	std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
	*this = src;	
	std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->name << ", " << this->title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer const	&Sorcerer::operator=(Sorcerer const &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->title = rhs.title;
	}
	return (*this);
}

std::string		Sorcerer::get_name(void) const
{
	return (this->name);
}

std::string		Sorcerer::get_title(void) const
{
	return (this->title);
}

void			Sorcerer::polymorph(Victim const &target) const
{
	target.getPolymorphed();
}

std::ostream	&operator<<(std::ostream &o, Sorcerer const &rhs)
{
	o << "I am " << rhs.get_name() << ", " << rhs.get_title() << ", and I like ponies !" << std::endl;
	return (o);
}
