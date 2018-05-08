/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 00:32:27 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/09 00:46:11 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_H
# define NINJATRAP_H

# include "ClapTrap.h"

class NinjaTrap : public ClapTrap
{
	NinjaTrap(void);
	NinjaTrap(std::string name);
	NinjaTrap(NinjaTrap const &src);
	~NinjaTrap(void);

	void	ninjaShoebox(ClapTrap const &trap) const;
	void	ninjaShoebox(FragTrap const &trap) const;
	void	ninjaShoebox(ScavTrap const &trap) const;
	void	ninjaShoebox(NinjaTrap const &trap) const;
}

#endif
