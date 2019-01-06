#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
	// check number of arguments
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace [filename] [s1] [s2]\n";
		return 1;
	}

	// check empty string
	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cerr << "At least one of the input argument is empty\n";
		return 1;
	}

	// open input file
	std::ifstream input_file(filename);
	if (input_file.fail())
	{
		std::cerr << "Can't open input file.\n";
		return 1;
	}

	// open output file
	std::ofstream output_file(filename + ".replace");
	if (output_file.fail())
	{
		std::cerr << "Can't open output file.\n";
		return 1;
	}

	// read, search, replace and write
	std::string line;
	std::size_t position;

	while (getline(input_file, line))
	{
		position = line.find(s1);
		while (position != std::string::npos)
		{
			line.replace(position, s1.size(), s2);
			position = line.find(s1, position + s2.size());
		}
		output_file << line << "\n";
	}

	// close files
	input_file.close();
	output_file.close();
	return 0;
}
