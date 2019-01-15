#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() :
	Form("Shrubbery Creation Form", 145, 137),
	_target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("Shrubbery Creation Form", 145, 137),
	_target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm::PresidentialPardonForm const & src) :
	Form("Shrubbery Creation Form", 145, 137),
	_target(src.getTarget())
{
	*this = src;
}

std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout << "Shrubbery execute.\n";
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm::PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
	{
		_target = rhs.getTarget();
	}
	return *this;
}