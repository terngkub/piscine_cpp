#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() :
	Form("presidential pardon", 25, 5),
	_target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("presidential pardon", 25, 5),
	_target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm::PresidentialPardonForm const & src) :
	Form("presidential pardon", 25, 5),
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
	try
	{
		checkBureaucrat(executor);

		std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
	}
	catch (std::exception & e)
	{
		throw;
	}
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm::PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
	{
		_target = rhs.getTarget();
	}
	return *this;
}