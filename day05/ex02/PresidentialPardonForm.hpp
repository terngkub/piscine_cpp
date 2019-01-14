#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();

private:
	std::string _target;

	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
};

#endif