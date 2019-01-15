#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("shrubbery creation", 145, 137),
	_target("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("shrubbery creation", 145, 137),
	_target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm::ShrubberyCreationForm const & src) :
	Form("shrubbery creation", 145, 137),
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
	try
	{
		checkBureaucrat(executor);

		std::ofstream file;
		file.open(_target + "_shrubbery");

		if (!file.is_open())
		{
			std::cout << "can't open file\n";
			return ;
		}
		
		file<< "   #\n"
			<< "  ##&\n"
			<< " #&#&#\n"
			<< "###&#&#\n"
			<< "   #\n";
		
		if (file.bad())
		{
			std::cout << "can't write file\n";
			return ;
		}

		file.close();
	}
	catch (std::exception & e)
	{
		throw;
	}
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm::ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
	{
		_target = rhs.getTarget();
	}
	return *this;
}
