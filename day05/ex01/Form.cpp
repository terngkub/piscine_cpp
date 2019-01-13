#include "Form.hpp"

Form::Form()
{
}

Form::Form(std::string name, bool signEd, int signGrade, int ExecGrade) :
	_name(name),
	_signed(signEd),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
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

Form & operator=(Form const & rhs)
{
	if (this != &rhs)
	{
		_signed = rhs.getSigned();
	}
	return *this;
}

std::string getName() const
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

void Form::beSigned(Bureaucrat bureaucrat)
{
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