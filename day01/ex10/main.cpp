#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::string str;

		while (getline(std::cin, str))
			std::cout << str << "\n";
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		std::ifstream ifs(argv[i]);
		
		if (!ifs.is_open())
		{
			std::cerr << "cato0tails: " << argv[i] << ": No such file or directory\n";
			continue;
		}

		char c = ifs.get();
		while (ifs.good())
		{
			std::cout << c;
			c = ifs.get();
		}

		ifs.close();
	}
	return 0;
}