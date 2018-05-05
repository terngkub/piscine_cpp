/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 13:52:00 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/05 17:25:55 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <fstream>
# include <ctime>
# include <map>

class Logger
{
	public:
		Logger(std::string filename);
		void		log(std::string const & dest, std::string const & message);

	private:
		typedef		void (Logger::*t_lfunc)(std::string);
		std::string	filename;
		void		logToConsole(std::string str);
		void		logToFile(std::string str);
		std::string	makeLogEntry(std::string str);
};

#endif
