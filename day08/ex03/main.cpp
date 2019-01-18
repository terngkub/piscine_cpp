#include <iostream>
#include <string>
#include "Mindopen.hpp"
#include "IInstruction.hpp"
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
	

	Plus * plus = new Plus();
	Dot * dot = new Dot();

	for (int i = 0; i < 33; i++)
		mindopen.addInstruction(plus);
	mindopen.addInstruction(dot);
	mindopen.execute();
	return 0;
}