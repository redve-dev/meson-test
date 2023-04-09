#include "../include/Logger.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <functional>

int TestLogger(bool exoected_to_print, const LogLevel logger_level, LogLevel message_level){
	static int test_no = 0;
	std::cout << "Test logger no: " << ++test_no << '\n';
	std::flush(std::cout);

	std::stringstream buffer;
	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

	Logger logger;
	logger.SetLogLevel(logger_level);
	std::string message = "Test debug" + std::to_string(test_no);
	logger.Log(message.c_str(), message_level);

	std::string output = buffer.str();
	std::cout.rdbuf(old);
	std::cout << output;

	std::cout << "End test logger no: " << test_no << "\n==========================\n\n";
	return exoected_to_print != output.empty(); }

int test_dumping_output(Logger& logger, size_t expected_lines){
	logger.Log("Test info", LogLevel::INFO);
	logger.Log("Test warning", LogLevel::WARNING);
	logger.Log("Test error", LogLevel::ERROR);
	logger.Log("Test debug", LogLevel::DEBUG);
	logger.Log("Test empty", LogLevel::EMPTY);
	logger.DumpLogsToFile("test.txt");
	std::ifstream file("test.txt");
	std::vector<std::string> lines;
	std::string line;
	while(std::getline(file, line)){
		std::cout << line << '\n';
		lines.push_back(line);
	}
	file.close();
	return static_cast<size_t>(lines.size()) != expected_lines;
}

int tests_logger_dumping_output(){
	int error = 0;
	Logger logger;
	auto function_cycle = std::function<void(LogLevel, int)>([&](LogLevel level, int expected){
		logger.SetLogLevel(level);
		error += test_dumping_output(logger, expected);
		logger.ClearLogs();
	});

	function_cycle(LogLevel::INFO, 4);
	function_cycle(LogLevel::WARNING, 3);
	function_cycle(LogLevel::ERROR, 2);
	function_cycle(LogLevel::DEBUG, 1);
	function_cycle(LogLevel::EMPTY, 0);
	return error;
}



int main(){
	int error = 0;
	//error += TestLogger(true, LogLevel::DEBUG, LogLevel::DEBUG); // fails
	//error += TestLogger(false, LogLevel::EMPTY, LogLevel::DEBUG);
	//error += tests_logger_dumping_output();
	return error;
}
