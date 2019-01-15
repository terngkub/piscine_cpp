#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("Shrubbery Creation Form", 145, 137),
	_target("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("Shrubbery Creation Form", 145, 137),
	_target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm::ShrubberyCreationForm const & src) :
	Form("Shrubbery Creation Form", 145, 137),
	_target(src.getTarget())
{
	*this = src;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	/*
	if (!getSigned())
		throw(NotSignedException());
	if (!hasEnoughExecGrade(executor))
		throw(GradeTooLowException());
		*/
	checkBureaucrat(executor);
	std::cout << "Shrubbery execute to "<< _target << "\n";
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm::ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
	{
		_target = rhs.getTarget();
	}
	return *this;
}

