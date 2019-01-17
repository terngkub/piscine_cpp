#include "NotFoundException.hpp"

NotFoundException::NotFoundException()
{
}

NotFoundException::~NotFoundException() throw()
{
}

const char * NotFoundException::what() const throw()
{
	return "value not found";
}

NotFoundException::NotFoundException(NotFoundException const & src)
{
	static_cast<void>(src);
}

NotFoundException & NotFoundException::operator=(NotFoundException const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}
