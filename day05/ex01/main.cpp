#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	Bureaucrat b1(20, "Bur One");
	Form f1("Form One", false, 100, 120);

	b1.signForm(f1);

}

int main()
{
	testForm();
	return 0;
}
