#ifndef NOTFOUNDEXCEPTION_HPP
# define NOTFOUNDEXCEPTION_HPP

#include <exception>

class NotFoundException : public std::exception
{
public:
	NotFoundException();
	NotFoundException(NotFoundException const & src);
	NotFoundException & operator=(NotFoundException const & rhs);
	~NotFoundException() throw();
	virtual const char * what() const throw();
};

#endif