#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() :
	Form("robotomy request", 72, 45),
	_target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("robotomy request", 72, 45),
	_target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm::RobotomyRequestForm const & src) :
	Form("robotomy request", 72, 45),
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
	try
	{
		checkBureaucrat(executor);

		if (rand() % 2 == 0)
			std::cout << _target << " has been robotomized successfully\n";
		else
			std::cout << _target << " has failed to be robotomized\n";
	}
	catch (std::exception & e)
	{
		throw;
	}
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm::RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
	{
		_target = rhs.getTarget();
	}
	return *this;
}
