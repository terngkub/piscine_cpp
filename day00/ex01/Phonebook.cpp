#include "Phonebook.hpp"
#include <iostream>
#include <limits>

Phonebook::Phonebook() : contact_nb(0) {}

void	Phonebook::add()
{
	if (contact_nb >= 8)
	{
		std::cout << "Phone book is full. You can only SEARCH and EXIT.\n";
		return ;
	}
	contact[contact_nb++].add();
}

void	Phonebook::search() const
{
	if (contact_nb == 0)
	{
		std::cout << "Phonebook is empty. Please ADD a contact.\n";
		return ;
	}
	for (int i = 0; i < contact_nb; i++)
		contact[i].preview(i);

	std::cout << "Enter an index: ";
	int index = -1;
	std::cin >> index;
	if (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Wrong input.\n";
	}
	else if (index < 0 || index >= contact_nb)
		std::cout << "Index out of range.\n";
	else
		contact[index].print();
}