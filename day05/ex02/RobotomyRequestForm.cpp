#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() :
	Form("Shrubbery Creation Form", 145, 137),
	_target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("Shrubbery Creation Form", 145, 137),
	_target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm::RobotomyRequestForm const & src) :
	Form("Shrubbery Creation Form", 145, 137),
	_target(src.getTarget())
{
	*this = src;
}

std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout << "Robo execute.\n";
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm::RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
	{
		_target = rhs.getTarget();
	}
	return *this;
}
