#include "Phonebook.hpp"
#include <iostream>

Phonebook::Phonebook() : contact_nb(0) {}

void	Phonebook::add()
{
	if (contact_nb >= 8)
	{
		std::cout << "Phone book is full\n";
		return ;
	}
	contact[contact_nb].add();
	contact_nb++;
}

void	Phonebook::search() const
{
	if (contact_nb == 0)
	{
		std::cout << "Phonebook is empty.\n";
		return ;
	}
	for (int i = 0; i < contact_nb; i++)
		contact[i].preview(i);
	while (1)
	{
		std::cout << "Enter an index: ";
		int index = -1;
		std::cin >> index;
		if (index < 0 || index >= contact_nb)
			std::cout << "Index out of range. Please try again.\n";
		else
		{
			contact[index].print();
			return ;
		}
	}
}