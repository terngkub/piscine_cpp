/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:44:40 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/04 20:45:53 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	// check parameter number
	if (argc != 4)
	{
		std::cout << "Wrong parameter number" << std::endl;
		return (1);
	}

	// check empty string
	std::string		filename(argv[1]);
	std::string		str1(argv[2]);
	std::string		str2(argv[3]);

	if (filename.empty() || str1.empty() || str2.empty())
	{
		std::cout << "At least one of the input is an empty string" << std::endl;
		return (1);
	}

	// check input file
	std::ifstream	input_file(filename);

	if (input_file.fail())
	{
		std::cout << "Can't open input file" << std::endl;
		return (1);
	}

	std::ofstream	output_file(filename + ".replace");
	std::string		line;
	std::size_t		position;

	while (getline(input_file, line))
	{
		position = line.find(str1);
		while (position != std::string::npos)
		{
			line.replace(position, str1.size(), str2);
			position = line.find(str1, position + str2.size());
		}
		output_file << line << std::endl;
	}

	input_file.close();
	output_file.close();
	return (0);
}
