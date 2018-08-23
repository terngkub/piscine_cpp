#include "Phonebook.hpp"
#include <iostream>

Phonebook::Phonebook() : maximum_contact(2), nb_contact(0) {}
Phonebook::~Phonebook() {};

void Phonebook::add_contact()
{
    if (nb_contact >= maximum_contact)
    {
        std::cout << "This phonebook is full. You can only SEARCH." << std::endl << std::endl;
        return ;
    }
    contacts[nb_contact++].add();
}

void Phonebook::search_contact()
{
    if (nb_contact == 0)
    {
        std::cout << "There is no contact in phonebook. Please ADD some before SEARCH." << std::endl;
        return ;
    }
    for (std::size_t i = 0; i < nb_contact; i++)
        contacts[i].preview(i);
    while (1)
    {
        std::cout << "Please choose an index: ";
        int index = -1;
        std::cin >> index;
        if (index < 0 || index >= (int)nb_contact)
            std::cout << "Index out of range. Please try again." << std::endl << std::endl;
        else
        {
            std::cout << std::endl;
            contacts[index].print();
            return ;
        }
    }
}
