/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:53:33 by terng             #+#    #+#             */
/*   Updated: 2018/05/01 16:19:03 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:

		Zombie(void);
		Zombie(std::string name, std::string type);
		~Zombie(void);

		void		announce(void);
		void		set_name(std::string name);
		void		set_type(std::string type);

	private:

		std::string	name;
		std::string	type;
};

#endif
