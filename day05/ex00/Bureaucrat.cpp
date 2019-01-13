#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(int grade, std::string name) :
	_grade(grade),
	_name(name)
{
	if (_grade < 1)
		throw(GradeTooHighException());
	else if (_grade > 150)
		throw(GradeTooLowException());
}


Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_grade = rhs._grade;
	}
	return *this;
}

std::string const Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade > 1)
		--_grade;
	else
		throw(GradeTooHighException());
}

void Bureaucrat::decrementGrade()
{
	if (_grade < 150)
		++_grade;
	else
		throw(GradeTooLowException());
}


GradeTooHighException::GradeTooHighException()
{
}

GradeTooHighException::~GradeTooHighException()
{
}

GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
}

GradeTooHighException & GradeTooHighException::operator=(GradeTooHighException const & rhs)
{
	(void)rhs;
	return *this;
}

virtual const char * GradeTooHighException::what() const throw()
{
	return "Grade too high\n";
}

GradeTooLowException::GradeTooLowException()
{
}

GradeTooLowException::~GradeTooLowException()
{
}

GradeTooLowException::GradeTooLowException(GradeTooLowException const & src)
{
}

GradeTooLowException & GradeTooLowException::operator=(GradeTooLowException const & rhs)
{
	(void)rhs;
	return *this;
}

virtual const char * GradeTooLowException::what() const throw()
{
	return "Grade too low\n";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat cosnt & rhs)
{
	o << "<" << _name << ">, bureaucrat grade <" << _grade << ">\n";
	return o;
}