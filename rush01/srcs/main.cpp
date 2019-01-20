#include <iostream>
#include "Monitor.hpp"

int main(int argc, char ** argv)
{
	if (argc > 2 || (argc == 2 && std::string(argv[1]) != "-shell" && std::string(argv[1]) != "-graphic"))
	{
		std::cerr << "Usage: ./ft_gkrellm [-shell|-graphic]\n";
		return 1;
	}
	else if (argc == 1)
	{
		Monitor monitor("-shell");
		monitor.run();
	}
	else if (argc == 2)
	{
		Monitor monitor(argv[1]);
		monitor.run();
	}
	return 0;
}
