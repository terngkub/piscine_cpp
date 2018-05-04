/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 20:49:38 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/04 22:01:46 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include <map>

class Human
{
	private:

		typedef void (Human::*t_action)(std::string const &);
		typedef std::pair<std::string, t_action> t_action_pair;

		void	meleeAttack(std::string const & target);
		void	rangedAttack(std::string const & target);
		void	intimidatingShout(std::string const & target);

	public:

		void	action(std::string const & action_name, std::string const & target);
};

#endif
