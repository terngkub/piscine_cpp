/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:05:08 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/11 00:06:51 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_H
# define VICTIM_H

# include <iostream>

class Victim
{
	public:
		Victim(void);
		Victim(std::string name);
		Victim(Victim const &src);
		~Victim(void);

		Victim const	&operator=(Victim const &rhs);

		std::string		get_name(void) const;
		virtual void	getPolymorphed(void) const;

	private:
		std::string		name;
};

std::ostream	&operator<<(std::ostream &o, Victim const &rhs);

#endif
