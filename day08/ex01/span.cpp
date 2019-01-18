#include "span.hpp"
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <limits>

Span::Span(unsigned int N) :
	_maxSize(N)
{
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (_number.size() >= _maxSize)
		throw(std::length_error("this Span object is full, cannot add more number"));
	_number.push_back(n);
	_isSorted = false;
}

void Span::bulkAddNumber(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	unsigned int size = end - beg;
	if (size + _number.size() > _maxSize)
		throw(std::length_error("an input is bigger than free space of the Span object"));
	for (; beg != end; ++beg)
		_number.push_back(*beg);
}

unsigned int Span::shortestSpan()
{
	if (_number.size() < 2)
		throw(std::length_error("the size is too low to find the shortest span"));

	unsigned int span;
	unsigned int minSpan = std::numeric_limits<unsigned int>::max();

	_sortNumber();
	for (std::vector<int>::iterator it = _number.begin() + 1; it != _number.end(); ++it)
	{
		span = std::abs(*it - *(it - 1));
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan()
{
	if (_number.size() < 2)
		throw(std::length_error("the size is too low to find the shortest span"));
	_sortNumber();
	return _number.back() - _number.front();
}

void Span::_sortNumber()
{
	if (!_isSorted)
	{
		std::sort(_number.begin(), _number.end());
		_isSorted = true;
	}
}