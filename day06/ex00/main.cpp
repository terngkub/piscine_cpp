#include <iostream>
#include "Convert.hpp"

int main(int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [string]\n";
		return 1;
	}

	char * end;
	double val = strtod(argv[1], &end);
	if (val == 0 && end == argv[1])
	{
		Convert convert(argv[1][0]);
		std::cout << convert;
	}
	else
	{
		Convert convert(val);
		std::cout << convert;
	}
	return 0;
}