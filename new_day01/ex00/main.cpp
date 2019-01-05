#include "Pony.hpp"

void ponyOnTheHeap()
{
	Pony *pony = new Pony("Pony on the heap");

	pony->announce();
	delete pony;
}

void ponyOnTheStack()
{
	Pony pony = Pony("Pony on the stack");

	pony.announce();
}

int main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
	return 0;
}
