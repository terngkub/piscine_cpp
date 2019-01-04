#include "Phonebook.hpp"
#include <iostream>

int	main(void)
{
	Phonebook	phonebook;
	std::string	command;

	while (1)
	{
		std::cout << "Enter command: ";
		std::cin >> command;
		if (command == "EXIT")
			return (0);
		else if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else
			std::cout << "Wrong command. Valid command: ADD, SEARCH, EXIT.\n";
	}
	return (0);
}