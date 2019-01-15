#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	Form * scf;
	Form * rrf;
	Form * ppf;
	Form * getFullPointOnThePiscineForm;

	scf = intern.makeForm("shrubbery creation", "one");
	rrf = intern.makeForm("robotomy request", "two");
	ppf = intern.makeForm("presidential pardon", "three");
	try
	{
		getFullPointOnThePiscineForm = intern.makeForm("get full point on the piscine form", "me");
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << "\n";
	std::cout << *scf << "\n";
	std::cout << *rrf << "\n";
	std::cout << *ppf << "\n";

	delete scf;
	delete rrf;
	delete ppf;

	return 0;
}
