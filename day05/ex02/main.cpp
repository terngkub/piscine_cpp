#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
void testBureaucrat()
{
	// Test constructor
	Bureaucrat one(2, "one");
	Bureaucrat two(149, "two");

	std::cout << one << "\n";
	std::cout << two << "\n";


	// Test increment/decrement

	one.incrementGrade();
	two.decrementGrade();

	std::cout << one << "\n";
	std::cout << two << "\n";

	// Test catching
	try
	{
		one.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "Got exception: " << e.what() << "\n";
	}
	try
	{
		two.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "Got exception: " << e.what() << "\n";
	}
	try
	{
		Bureaucrat three(0, "three");
	}
	catch (std::exception & e)
	{
		std::cout << "Got exception: " << e.what() << "\n";
	}
	try
	{
		Bureaucrat four(151, "three");
	}
	catch (std::exception & e)
	{
		std::cout << "Got exception: " << e.what() << "\n";
	}
}

void testForm()
{
	// Test constructor
	Form f1("Form One", 100, 100);

	try
	{
		Form f2("Form Two", 151, 100);
	}
	catch (std::exception & e)
	{
		std::cout << "Got exceptiop for signGrade: " << e.what() << "\n";
	}

	try
	{
		Form f3("Form Two", 0, 100);
	}
	catch (std::exception & e)
	{
		std::cout << "Got exception for signGrade: " << e.what() << "\n";
	}

	try
	{
		Form f4("Form Four", 100, 151);
	}
	catch (std::exception & e)
	{
		std::cout << "Got exceptiop for execGrade: " << e.what() << "\n";
	}

	try
	{
		Form f5("Form Two", 100, 0);
	}
	catch (std::exception & e)
	{
		std::cout << "Got exception for execGrade: " << e.what() << "\n";
	}

	// Test sign	

	Bureaucrat b1(120, "Bur One");
	Bureaucrat b2(20, "Bur Two");

	b1.signForm(f1);
	try
	{
		b2.signForm(f1);
	}
	catch (std::exception & e)
	{
		std::cout << "Got exception for sign: " << e.what() << "\n";
	}
}
*/

void testShrubberyCreationForm()
{
	ShrubberyCreationForm	scf("AAA");
	RobotomyRequestForm		rrf("BBB");
	PresidentialPardonForm	ppf("CCC");

	Bureaucrat				good(1, "Good");
	Bureaucrat				bad(150, "Bad");

	std::cout << "Fail to sign\n";
	std::cout << "_____________________________\n";
	bad.signForm(scf);
	bad.signForm(rrf);
	bad.signForm(ppf);

	std::cout << "\nFail to Execute because the form isn't sign\n";
	std::cout << "_____________________________\n";
	good.executeForm(scf);
	good.executeForm(rrf);
	good.executeForm(ppf);

	std::cout << "\nSuccess to sign\n";
	std::cout << "_____________________________\n";
	good.signForm(scf);
	good.signForm(rrf);
	good.signForm(ppf);

	std::cout << "\nFail to Execute because the exec grade isn't enough\n";
	std::cout << "_____________________________\n";
	bad.executeForm(scf);
	bad.executeForm(rrf);
	bad.executeForm(ppf);

	std::cout << "\nSuccess to execute form\n";
	std::cout << "_____________________________\n";
	good.executeForm(scf);
	good.executeForm(rrf);
	good.executeForm(ppf);
}

int main()
{
	testShrubberyCreationForm();
	return 0;
}
