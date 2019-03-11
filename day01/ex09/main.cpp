#include "Logger.hpp"

int main()
{
	Logger logger = Logger("log");
	logger.log("console", "test console log 1");
	logger.log("console", "test console log 2");
	logger.log("file", "test file log 1");
	logger.log("file", "test file log 2");
	return 0;
}