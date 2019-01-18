#include <iostream>
#include <string>
#include "Mindopen.hpp"
#include "IInstruction.hpp"
#include "Dot.hpp"
#include "Plus.hpp"

int main()
{
	Plus plus = Plus();
	Dot dot = Dot();

	Mindopen mindopen;
	for (int i = 0; i < 33; i++)
		mindopen.addInstruction(plus);
	mindopen.addInstruction(dot);
	mindopen.execute();
	return 0;
}