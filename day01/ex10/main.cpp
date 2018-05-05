/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:22:18 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/05 18:54:16 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::string	str;

		while (getline(std::cin, str))
			std::cout << str << std::endl;
	}
	else
	{
		for	(int i = 1; i < argc; i++)
		{
			std::ifstream	ifs(argv[i]);
			if (!ifs.is_open())
			{
				std::cout << "cato9tail: " << argv[i] << ": No such file or directory" << std::endl;
				return (1);
			}

			char c = ifs.get();
			while (ifs.good())
			{
				std::cout << c;
				c = ifs.get();
			}

			ifs.close();
		}
	}
	return (0);
}
