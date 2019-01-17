#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> a1(3);

	std::cout << "<a1> val: " << a1[0] << "\n";
	std::cout << "<a1> size: " << a1.size() << "\n";
	a1[0] = 10;
	std::cout << "<a1> new val: " << a1[0] << "\n\n";

	Array<int> a2(a1);
	std::cout << "<a2> val: " << a2[0] << "\n";
	std::cout << "<a2> size: " << a1.size() << "\n\n";

	Array<int> a3(2);
	std::cout << "<a3> val: " << a3[0] << "\n";
	std::cout << "<a3> size: " << a3.size() << "\n";
	a3 = a1;
	std::cout << "a3 assign from a1\n";
	std::cout << "<a3> val: " << a3[0] << "\n";
	std::cout << "<a3> size: " << a3.size() << "\n\n";
	
	try
	{
		std::cout << a1[10] << "\n";
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << "\n";
	}
	return 0;
}