#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() :
	_name(""),
	_signGrade(150),
	_execGrade(150)
{
}

Form::Form(std::string name, int signGrade, int execGrade) :
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw(GradeTooHighException());
	else if (_signGrade > 150 || _execGrade > 150)
		throw(GradeTooLowException());
}

Form::Form(Form const & src) :
	_name(src.getName()),
	_signed(src.getSigned()),
	_signGrade(src.getSignGrade()),
	_execGrade(src.getExecGrade())
{
}

Form::~Form()
{
}

Form & Form::operator=(Form const & rhs)
{
	if (this != &rhs)
		_signed = rhs.getSigned();
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
		_signed = true;
	else
		throw(GradeTooLowException());
}

void Form::checkBureaucrat(Bureaucrat const & bureaucrat) const
{
	if (!getSigned())
		throw(NotSignedException());
	if (bureaucrat.getGrade() > _execGrade)
		throw(GradeTooLowException());
}

Form::GradeTooHighException::GradeTooHighException()
{
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

Form::GradeTooHighException::GradeTooHighException(Form::GradeTooHighException const & src)
{
	*this = src;
}

Form::GradeTooHighException & Form::GradeTooHighException::operator=(Form::GradeTooHighException const & rhs)
{
	(void)rhs;
	return *this;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

Form::GradeTooLowException::GradeTooLowException()
{
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

Form::GradeTooLowException::GradeTooLowException(Form::GradeTooLowException const & src)
{
	*this = src;
}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(Form::GradeTooLowException const & rhs)
{
	(void)rhs;
	return *this;
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

Form::NotSignedException::NotSignedException()
{
}

Form::NotSignedException::~NotSignedException() throw()
{
}

Form::NotSignedException::NotSignedException(Form::NotSignedException const & src)
{
	*this = src;
}

Form::NotSignedException & Form::NotSignedException::operator=(Form::NotSignedException const & rhs)
{
	(void)rhs;
	return *this;
}

const char * Form::NotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
	o << "Form <" << rhs.getName() << "> is ";
	if (rhs.getSigned())
		o << "signed";
	else
		o << "unsigned";
	o << ", the required grade to sign is " << rhs.getSignGrade()
		<< " and the required grade to execute is " << rhs.getExecGrade() << ".";
	return o;
}