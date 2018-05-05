/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 14:23:04 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/05 17:37:37 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(std::string filename) : filename(filename) {}

std::string Logger::makeLogEntry(std::string str)
{
	time_t		now = time(0);
	std::string	date = ctime(&now);
	
	return date.substr(0, date.size() - 1) + " " + str;
}

void	Logger::logToConsole(std::string str)
{
	std::cout << makeLogEntry(str) << std::endl;
}

void	Logger::logToFile(std::string str)
{
	std::ofstream	log_file;
	log_file.open(this->filename, std::ios_base::app);

	if (!log_file.is_open())
	{
		std::cout << "Couldn not open " << this->filename << std::endl;
		return ;
	}

	log_file << makeLogEntry(str) << std::endl;

	if (log_file.bad())
	{
		std::cout << "Could not save to " << this->filename << std::endl;
		return ;
	}

	log_file.close();
}

void		Logger::log(std::string const & dest, std::string const & message)
{
	std::map<std::string, t_lfunc>	dests;
	dests.insert( std::pair<std::string, t_lfunc>("console", &Logger::logToConsole) );
	dests.insert( std::pair<std::string, t_lfunc>("file", &Logger::logToFile) );

	if (dests.find(dest) != dests.end())
		(this->*dests[dest])(message);
	else
		std::cout << "Could not find dest" << std::endl;
}
