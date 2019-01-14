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

Bureaucrat::Bureaucrat(Bureaucrat const & src) :
	_grade(src.getGrade()),
	_name(src.getName())
{
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
	{
		_grade = rhs.getGrade();
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


Bureaucrat::GradeTooHighException::GradeTooHighException()
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(Bureaucrat::GradeTooHighException const & src)
{
	*this = src;
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const & rhs)
{
	(void)rhs;
	return *this;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(Bureaucrat::GradeTooLowException const & src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const & rhs)
{
	(void)rhs;
	return *this;
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << "<" << rhs.getName() << ">, bureaucrat grade <" << rhs.getGrade() << ">";
	return o;
}