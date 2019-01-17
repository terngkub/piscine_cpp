#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	std::cout << *easyfind< std::vector<int> >(v, 2) << "\n";
	try
	{
		std::cout << *easyfind< std::vector<int> >(v, 5) << "\n";
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}
	return 0;
}