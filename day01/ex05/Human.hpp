/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:10:32 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/01 17:29:25 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human
{
	public:

		Human(void);

		Brain		getBrain(void);
		std::string	identify(void);

	private:

		Brain const	brain;
};

#endif
