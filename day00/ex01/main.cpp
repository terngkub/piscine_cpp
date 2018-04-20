/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:48:35 by nkamolba          #+#    #+#             */
/*   Updated: 2018/04/20 17:49:55 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

static void	search(Contact contacts[8], int nb_of_contacts)
{
	int			index;

	index = 0;
	while (index < nb_of_contacts)
	{
		contacts[index].print_list(index);
		index++;
	}
	std::cout << "Please input the index: ";
	std::cin >> index;
	if (index >= 0 && index < nb_of_contacts)
		contacts[index].print_contact();
	else
		std::cout << "Wrong input. The program will exit the search." << std::endl;
}

int			main(void)
{
	Contact		contacts[8];
	int			nb_of_contacts;
	std::string	command;

	nb_of_contacts = 0;
	while (1)
	{
		std::cout << "Type your command: ";
		std::cin >> command;
		if (command.compare("ADD") == 0 && nb_of_contacts < 8)
		{
			if (nb_of_contacts < 8)
				contacts[nb_of_contacts++].add();
			else
				std::cout << "The phonebook is full. You can only SEARCH now." << std::endl;
		}
		else if (command.compare("SEARCH") == 0)
			search(contacts, nb_of_contacts);
		else if (command.compare("EXIT") == 0)
			break;
		else
			std::cout << "Wrong command. Please try again." << std::endl;
	}
	return (0);
}
