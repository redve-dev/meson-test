#include <iostream>
#include <list>

class Logger{
	public:
		enum class LogLevel{
			INFO,
			WARNING,
			ERROR,
			DEBUG,
			EMPTY
		};
	private:
		LogLevel logLevel;
		static std::list<std::string> logMessages;
		void dumpLogMessages(std::ostream&) noexcept;
	public:
		Logger() noexcept;
		void Log(const char* message, const LogLevel logLevel) noexcept;
		void SetLogLevel(const LogLevel logLevel) noexcept;
		void DumpLogsToFile(const char* fileName) ;
		void DumpLogsToStdout() noexcept;
		void ClearLogs() noexcept;
};
