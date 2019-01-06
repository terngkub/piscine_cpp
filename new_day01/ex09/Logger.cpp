#include "Logger.hpp"
#include <fstream>
#include <iostream>

Logger::Logger(std::string filename)
: _log_name(filename)
{}

void Logger::log(std::string const & dest, std::string const & message)
{
	std::string dest_array[] = {"console", "file"};
	void (Logger::*function_array[])(std::string) const = {&Logger::logToConsole, &Logger::logToFile};
	std::string log_entry = makeLogEntry(message);

	for (int i = 0; i < 2; i ++)
		if (dest == dest_array[i])
			(this->*function_array[i])(log_entry);
}

void Logger::logToConsole(std::string message) const
{
	std::cout << message;
}

void Logger::logToFile(std::string message) const
{
	std::ofstream log_file;
	log_file.open(_log_name, std::ios_base::app);
	if (log_file.fail())
		std::cerr << "Can't open log file.\n";
	log_file << message;
	log_file.close();
}

std::string Logger::makeLogEntry(std::string message) const
{
	time_t now = time(0);
	std::string date = ctime(&now);
	return "[" + date.substr(0, date.size() - 1) + "] " + message + "\n";
}