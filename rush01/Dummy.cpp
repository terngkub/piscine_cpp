#include "Dummy.hpp"
#include <cstdlib>

Dummy::Dummy() {}
Dummy::~Dummy() {}

std::string Dummy::getInfo()
{
	std::string str[] = {"aaa", "bbb", "ccc"};
	srand(time(NULL));
	return str[rand() % 3];
}