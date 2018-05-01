/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:47:40 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/01 17:31:52 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

std::string	Brain::identify(void) const
{
	std::ostringstream	adr;
	std::string			str;

	adr << (void const *)this;
	str = adr.str();
	return str;
}
