#include <iostream>
#include <string>
#include "Mindopen.hpp"
#include "AInstruction.hpp"
#include "Dot.hpp"
#include "Plus.hpp"

int main(int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./mindopen [file]";
		return 1;
	}
	Mindopen mindopen(argv[1]);
	try
	{
		mindopen.execute();
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << "\n";
	}
	return 0;
}