#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
public:
	Span(unsigned int N);
	~Span();

	void addNumber(int n);
	void bulkAddNumber(std::vector<int>::iterator beg, std::vector<int>::iterator end);
	unsigned int shortestSpan();
	unsigned int longestSpan();


private:
	unsigned int _maxSize;
	std::vector<int> _number;
	bool _isSorted;

	void _sortNumber();
};

#endif
