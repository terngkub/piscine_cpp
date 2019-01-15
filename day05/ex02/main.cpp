#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

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

/*
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
	ShrubberyCreationForm scf("home");
	Bureaucrat exe(140, "abc");

	exe.signForm(scf);
	exe.executeForm(scf);
}

int main()
{
	testShrubberyCreationForm();
	return 0;
}
