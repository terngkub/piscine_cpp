#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Form.hpp"

class Intern
{
public:
	Intern();
	~Intern();

	Form * makeForm(std::string _formName, std::string _target);

	class FormNotFoundException : public std::exception
	{
	public:
		FormNotFoundException();
		~FormNotFoundException() throw();
		FormNotFoundException(FormNotFoundException const & src);
		FormNotFoundException & operator=(FormNotFoundException const & rhs);
		virtual const char * what() const throw();
	};

private:
	std::string _formName;
	std::string _target;

	Intern(Intern const & src);
	Intern & operator=(Intern const & rhs);
};

#endif