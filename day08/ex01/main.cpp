#include "span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);
	std::vector<int> v;
	v.push_back(5);
	v.push_back(3);
	v.push_back(17);
	v.push_back(9);
	v.push_back(11);
	sp.bulkAddNumber(v.begin(), v.end());

	/*
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	*/

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}