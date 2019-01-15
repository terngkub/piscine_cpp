#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
public:
	Form(std::string name, int signGrade, int ExecGrade);
	Form(Form const & src);
	virtual ~Form();
	Form & operator=(Form const & rhs);

	std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	
	void beSigned(Bureaucrat const & bureaucrat);
	void checkBureaucrat(Bureaucrat const & bureaucrat) const;
	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		~GradeTooHighException() throw();
		GradeTooHighException(GradeTooHighException const & src);
		GradeTooHighException & operator=(GradeTooHighException const & rhs);
		virtual const char * what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		~GradeTooLowException() throw();
		GradeTooLowException(GradeTooLowException const & src);
		GradeTooLowException & operator=(GradeTooLowException const & rhs);
		virtual const char * what() const throw();
	};

	class NotSignedException : public std::exception
	{
	public:
		NotSignedException();
		~NotSignedException() throw();
		NotSignedException(NotSignedException const & src);
		NotSignedException & operator=(NotSignedException const & rhs);
		virtual const char * what() const throw();
	};

private:
	Form();

	std::string const _name;
	bool _signed;
	int const _signGrade;
	int const _execGrade;
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif