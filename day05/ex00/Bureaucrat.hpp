#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

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
	int _grade;
	std::string const _name;

	Bureaucrat();

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif