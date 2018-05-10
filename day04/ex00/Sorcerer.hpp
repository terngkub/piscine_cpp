/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:57:56 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/11 00:07:55 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_H
# define SORCERER_H

# include <iostream>
# include "Victim.hpp"
# include "Peon.hpp"

class Sorcerer
{
	public:
		Sorcerer(void);
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const &src);
		~Sorcerer(void);

		Sorcerer const	&operator=(Sorcerer const &rhs);

		std::string		get_name(void) const;
		std::string		get_title(void) const;
		void			polymorph(Victim const &target) const;

	private:
		std::string		name;
		std::string		title;
};

std::ostream			&operator<<(std::ostream &o, Sorcerer const &rhs);

#endif
