#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T con, int n)
{
	typename T::iterator it = std::find(con.begin(), con.end(), n);
	if (it == con.end())
		throw std::runtime_error("value not found");
	return it;
}

#endif
