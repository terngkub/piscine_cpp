#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Form;

class Bureaucrat
{
public:
	Bureaucrat(int grade, std::string name);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat & operator=(Bureaucrat const & rhs);

	std::string const getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();
	void signForm(Form & form) const;

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

private:
	Bureaucrat();

	int _grade;
	std::string const _name;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif