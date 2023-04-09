#include <iostream>
#include "../include/Logger.hpp"

int main(){
	Logger logger;
	logger.SetLogLevel(Logger::LogLevel::WARNING);
	logger.Log("Hello World!", Logger::LogLevel::INFO);
	logger.Log("warning ", Logger::LogLevel::WARNING);
	logger.Log("error log", Logger::LogLevel::ERROR);
	logger.Log("debug log", Logger::LogLevel::DEBUG);
	logger.Log("empty log", Logger::LogLevel::EMPTY);
	//logger.DumpLogsToStdout();
	//logger.DumpLogsToFile("test_log.txt");

	return 0;
}
