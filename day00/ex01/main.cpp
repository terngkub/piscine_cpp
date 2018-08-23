#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream> 
#include <string>

std::string get_command()
{
    std::cout << "Please in put a command [ADD|SEARCH|EXIT]: ";
    std::string command;
    std::cin >> command;
    return command;
}

int main()
{
    Phonebook phonebook;

    while (1)
    {
        std::string  command = get_command();
        if (command == "EXIT")
            return 0;
        else if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search_contact();
        else
            std::cout << "Wrong command.\n";
    }
    return 0;
}