/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:49:00 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/01 17:16:07 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int	main(void)
{
	Human	bob;

	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
	return (0);
}
