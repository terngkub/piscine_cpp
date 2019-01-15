#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const & src)
{
	(void)src;
}

Intern::~Intern()
{
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

Form * Intern::makeForm(std::string formName, std::string target)
{
	Form * form;

	if (formName == "shrubbery creation")
		form = new ShrubberyCreationForm(target);
	else if (formName == "robotomy request")
		form = new RobotomyRequestForm(target);
	else if (formName == "presidential pardon")
		form = new PresidentialPardonForm(target);
	else
		throw(FormNotFoundException());
	std::cout << "Intern creates " << form->getName() << "\n";
	return form;
}

Intern::FormNotFoundException::FormNotFoundException()
{
}

Intern::FormNotFoundException::~FormNotFoundException() throw()
{
}

Intern::FormNotFoundException::FormNotFoundException(Intern::FormNotFoundException const & src)
{
	*this = src;
}

Intern::FormNotFoundException & Intern::FormNotFoundException::operator=(Intern::FormNotFoundException const & rhs)
{
	(void)rhs;
	return *this;
}

const char * Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}