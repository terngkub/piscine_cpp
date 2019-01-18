#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template< typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;

	iterator begin()
	{
		return std::stack<T, Container>::c.begin();
	}

	iterator end()
	{
		return std::stack<T, Container>::c.end();
	}

	const_iterator begin() const
	{
		return std::stack<T, Container>::c.begin();
	}

	const_iterator end() const
	{
		return std::stack<T, Container>::c.end();
	}
};

#endif