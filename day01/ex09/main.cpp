/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 14:34:52 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/05 17:35:51 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int	main(void)
{
	Logger	logger("log.txt");

	logger.log("console", "From log(console)");
	logger.log("file", "From log(file)");
	logger.log("abc", "From log(abc)");
	return (0);
}
