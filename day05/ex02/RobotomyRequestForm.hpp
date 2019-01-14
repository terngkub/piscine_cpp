#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();

private:
	std::string _target;

	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const & src);
	RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
};

#endif