/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:07:48 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/11 00:08:35 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_H
# define PEON_H

# include "Victim.hpp"

class Peon : public Victim
{
	public:
		Peon(void);
		Peon(std::string name);
		Peon(Peon const &src);
		~Peon(void);
		
		virtual void	getPolymorphed(void) const;
};

std::ostream			&operator<<(std::ostream &o, Peon const &rhs);

#endif
