#pragma once
#include "Contact.hpp"

class Phonebook
{
public:
    Phonebook();
    ~Phonebook();
    void add_contact();
    void search_contact();

private:
    const std::size_t maximum_contact;
    std::size_t nb_contact;
    Contact contacts[8];
};