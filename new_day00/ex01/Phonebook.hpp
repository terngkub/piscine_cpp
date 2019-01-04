#pragma once
#include "Contact.hpp"

class Phonebook
{
public:
	Phonebook();
	void	add();
	void	search() const;

private:
	Contact	contact[8];
	int		contact_nb;
};