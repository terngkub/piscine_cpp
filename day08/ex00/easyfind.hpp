#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include "NotFoundException.hpp"

template<typename T>
typename T::iterator easyfind(T con, int n)
{
	typename T::iterator it = std::find(con.begin(), con.end(), n);
	if (it == con.end())
		throw NotFoundException();
	return it;
}

#endif