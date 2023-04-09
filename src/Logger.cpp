#include "../include/Logger.hpp"
#include <cstdio>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <chrono>

std::list<std::string> Logger::logMessages;

Logger::Logger() noexcept: 
	logLevel(LogLevel::INFO)
{
}

void Logger::Log(const char* message, const LogLevel level) noexcept {
	const std::unordered_map<LogLevel, const char*> logLevelMap = {
		{LogLevel::INFO, "INFO"},
		{LogLevel::WARNING, "WARNING"},
		{LogLevel::ERROR, "ERROR"},
		{LogLevel::DEBUG, "DEBUG"},
		{LogLevel::EMPTY, ""},
	};
	if (level >= Logger::logLevel && level != LogLevel::EMPTY){
		std::stringstream ss;
		const auto now = std::chrono::system_clock::now();
		const auto now_c = std::chrono::system_clock::to_time_t(now);
		ss << std::put_time(std::localtime(&now_c), "%X") << " | ";
		ss << std::setw(80) << std::left<< message <<" | "<< std::setw(8)<<logLevelMap.at(level);
		logMessages.push_back(ss.str().c_str());
	}
}

void Logger::SetLogLevel(const LogLevel level) noexcept {
	Logger::logLevel = level;
}

void Logger::dumpLogMessages(std::ostream& os) noexcept {
	for (auto& message : logMessages){
		os << message << '\n';
	}
}

void Logger::DumpLogsToFile(const char* fileName) {
	std::ofstream file(fileName);
	if (!file.is_open()){
		std::cerr << "Could not open file: " << fileName << std::endl;
		return;
	}
	dumpLogMessages(file);
}

void Logger::DumpLogsToStdout() noexcept {
	dumpLogMessages(std::cout);
}

void Logger::ClearLogs() noexcept {
	logMessages.clear();
}
