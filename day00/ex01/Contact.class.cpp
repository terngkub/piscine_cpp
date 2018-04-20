/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:12:17 by nkamolba          #+#    #+#             */
/*   Updated: 2018/04/20 17:47:54 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

void		Contact::add(void)
{
	std::cout << "first name: ";
	std::cin >> this->first_name;
	std::cout << "last name: ";
	std::cin >> this->last_name;
	std::cout << "nickname: ";
	std::cin >> this->nickname;
	std::cout << "login: ";
	std::cin >> this->login;
	std::cout << "postal address: ";
	std::cin >> this->postal_address;
	std::cout << "email address: ";
	std::cin >> this->email_address;
	std::cout << "phone number: ";
	std::cin >> this->phone_number;
	std::cout << "birthday date: ";
	std::cin >> this->birthday_date;
	std::cout << "favorite meal: ";
	std::cin >> this->favorite_meal;
	std::cout << "underwear color: ";
	std::cin >> this->underwear_color;
	std::cout << "darkest secret: ";
	std::cin >> this->darkest_secret;
	std::cout << "Contact added." << std::endl;
}

static void	print_column(std::string str)
{
	if (str.length() < 10)
		std::cout << std::setw (10) << str;
	else
		std::cout << str.substr(0, 9) << ".";
}

void		Contact::print_list(int index) const
{
	std::cout << std::setw (10) << index << "|";
	print_column(this->first_name);
	std::cout << "|";
	print_column(this->last_name);
	std::cout << "|";
	print_column(this->nickname);
	std::cout << std::endl;
}

void		Contact::print_contact(void) const
{
	std::cout << "first name: " << this->first_name << std::endl;
	std::cout << "last name: " << this->last_name << std::endl;
	std::cout << "nickname: " << this->nickname << std::endl;
	std::cout << "login: " << this->login << std::endl;
	std::cout << "postal address: " << this->postal_address << std::endl;
	std::cout << "email address: " << this->email_address << std::endl;
	std::cout << "phone number: " << this->phone_number << std::endl;
	std::cout << "birthday date: " << this->birthday_date << std::endl;
	std::cout << "favorite meal: " << this->favorite_meal << std::endl;
	std::cout << "underwear color: " << this->underwear_color << std::endl;
	std::cout << "darkest secret: " << this->darkest_secret << std::endl;
}
