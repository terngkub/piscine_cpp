/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:21:08 by terng             #+#    #+#             */
/*   Updated: 2018/04/26 11:42:25 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap(void)
{
	Pony *pony = new Pony("Heap");

	pony->getName();
	delete pony;
}

void	ponyOnTheStack(void)
{
	Pony pony = Pony("Stack");

	pony.getName();
}

int	main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
	return (0);
}
