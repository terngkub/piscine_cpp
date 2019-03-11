#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>

class Logger
{
public:
	Logger(std::string filename);
	void		log(std::string const & dest, std::string const & message);

private:
	std::string	_log_name;

	void		logToConsole(std::string msg) const;
	void		logToFile(std::string msg) const;
	std::string	makeLogEntry(std::string msg) const;
};

#endif