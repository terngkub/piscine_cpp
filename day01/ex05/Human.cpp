/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:10:21 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/01 17:28:46 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void) : brain(Brain())
{
}

Brain		Human::getBrain(void)
{
	return this->brain;
}

std::string	Human::identify(void)
{
	return this->brain.identify();
}
