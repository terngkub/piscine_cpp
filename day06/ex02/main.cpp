#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	srand(time(NULL));
	int n = rand() % 3;
	if (n == 0)
		return new A();
	else if (n == 1)
		return new B();
	else
		return new C();
}

void identify_from_pointer( Base * p )
{
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
}

void identify_from_reference( Base & p )
{
	try
	{
		A & a = dynamic_cast<A &>(p);
		static_cast<void>(a);
		std::cout << "A\n";
		return ;
	}
	catch (std::bad_cast & bc)
	{
	}
	try
	{
		B & b = dynamic_cast<B &>(p);
		static_cast<void>(b);
		std::cout << "B\n";
		return ;
	}
	catch (std::bad_cast & bc)
	{
	}
	try
	{
		C & c = dynamic_cast<C &>(p);
		static_cast<void>(c);
		std::cout << "C\n";
		return ;
	}
	catch(std::bad_cast & bc)
	{
	}
}

int main()
{
	std::cout << "Test generate\n";
	std::cout << "-----------------\n";
	Base * base = generate();
	identify_from_pointer(base);
	delete base;

	A a;
	B b;
	C c;

	std::cout << "\nTest pointer cast\n";
	std::cout << "-----------------\n";
	identify_from_pointer(&a);
	identify_from_pointer(&b);
	identify_from_pointer(&c);

	std::cout << "\nTest reference cast\n";
	std::cout << "-----------------\n";
	identify_from_reference(a);
	identify_from_reference(b);
	identify_from_reference(c);

	return 0;
}