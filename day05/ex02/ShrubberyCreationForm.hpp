#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();

	std::string getTarget() const;
	
	void execute(Bureaucrat const & executor) const;

private:
	std::string _target;

	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
};

#endif