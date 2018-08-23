#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::add()
{
    std::cout << "first name: ";
    std::cin >> first_name;
    std::cout << "last name: ";
    std::cin >> last_name;
    std::cout << "nickname: ";
    std::cin >> nickname;
    std::cout << "login: ";
    std::cin >> login;
    std::cout << "postal address: ";
    std::cin >> postal_address;
    std::cout << "email address: ";
    std::cin >> email_address;
    std::cout << "phone number: ";
    std::cin >> phone_number;
    std::cout << "birthday date: ";
    std::cin >> birthday_date;
    std::cout << "favorite meal: ";
    std::cin >> favorite_meal;
    std::cout << "underwear color: ";
    std::cin >> underwear_color;
    std::cout << "darkest secret: ";
    std::cin >> darkest_secret;
}

static void print_column(std::string str)
{
    if (str.length() < 10)
        std::cout << std::setw (10) << str;
    else
        std::cout << str.substr(0, 9) << ".";
}

void Contact::preview(std::size_t index) const
{
    std::cout << std::setw (10) << index << "|";
    print_column(first_name);
    std::cout << "|";
    print_column(last_name);
    std::cout << "|";
    print_column(nickname);
    std::cout << std::endl;
}

void Contact::print() const
{
	std::cout << "first name: " << first_name << std::endl;
	std::cout << "last name: " << last_name << std::endl;
	std::cout << "nickname: " << nickname << std::endl;
	std::cout << "login: " << login << std::endl;
	std::cout << "postal address: " << postal_address << std::endl;
	std::cout << "email address: " << email_address << std::endl;
	std::cout << "phone number: " << phone_number << std::endl;
	std::cout << "birthday date: " << birthday_date << std::endl;
	std::cout << "favorite meal: " << favorite_meal << std::endl;
	std::cout << "underwear color: " << underwear_color << std::endl;
	std::cout << "darkest secret: " << darkest_secret << std::endl;
}