/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 21:11:18 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/04 22:03:52 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int	main(void)
{
	Human	human;

	human.action("meleeAttack", "target");
	human.action("rangedAttack", "target");
	human.action("intimidatingShout", "target");
	human.action("dance", "target");
	return (0);
}
