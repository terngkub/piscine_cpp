#include "span.hpp"
#include <iostream>

#define NUMBER 1000

int main()
{
	Span sp1 = Span(5);
	sp1.addNumber(5);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;
	std::cout << "\n";

	Span sp2 = Span(5);
	std::vector<int> v1;
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(17);
	v1.push_back(9);
	v1.push_back(11);
	sp2.bulkAddNumber(v1.begin(), v1.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	std::cout << "\n";

	Span sp3 = Span(NUMBER);
	std::vector<int> v2(NUMBER);
	srand(time(NULL));
	std::generate(v2.begin(), v2.end(), rand);
	sp3.bulkAddNumber(v2.begin(), v2.end());
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;
	return 0;
}