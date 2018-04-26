/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:40:46 by terng             #+#    #+#             */
/*   Updated: 2018/04/26 13:48:16 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	memoryLeak()
{
	std::string*	panthere = new std::string("Stirng panthere");
	std::cout << *panthere << std::endl;
	delete panthere;
}

/*
int		main(void)
{
	memoryLeak();
	return (0);
}
*/
