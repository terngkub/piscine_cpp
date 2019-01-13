#include <iostream>
#include "Bureaucrat.hpp"

int main()
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

	return 0;
}
