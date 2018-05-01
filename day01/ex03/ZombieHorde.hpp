/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:57:46 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/01 16:20:54 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class ZombieHorde
{
	public:

		ZombieHorde(int N);
		~ZombieHorde();

		void	announce(void);

	private:

		Zombie		*zombies;
		int			size;

};

#endif
