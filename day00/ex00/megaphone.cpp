/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:27:18 by nkamolba          #+#    #+#             */
/*   Updated: 2018/04/20 15:34:47 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
				std::cout << (char)toupper(argv[i][j++]);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
