#pragma once
#include <any>
#include <memory>
#include <string>
#include <cassert>

class Logger
{
public:
	enum class Severity
	{
		INFO,
		WARN,
		ERR
	};

	virtual ~Logger() = default;
	Logger& operator=(const Logger&) = delete;
	Logger& operator=(const Logger&&) = delete;

	static void Initialize();
	static void Destroy();

	static void Log(const std::string_view& message, Severity sev = Severity::INFO);
	static void Log(const std::string& message, Severity sev = Severity::INFO);
	static void Log(const char* message, Severity sev = Severity::INFO);

	static void LogF(const std::string_view& message, Severity sev);
	static void LogF(const std::string& message, Severity sev);
	static void LogF(const char* message, Severity sev);

	template <typename... Args>
	static void LogF(const std::string_view& message, Severity sev, Args... args);
	template <typename... Args>
	static void LogF(const std::string& message, Severity sev, Args... args);
	template <typename... Args>
	static void LogF(const char* message, Severity sev, Args... args);

	static void DLog(const std::string_view& message, Severity sev = Severity::INFO);
	static void DLog(const std::string& message, Severity sev = Severity::INFO);
	static void DLog(const char* message, Severity sev = Severity::INFO);

	static void DLogF(const std::string_view& message, Severity sev);
	static void DLogF(const std::string& message, Severity sev);
	static void DLogF(const char* message, Severity sev);


	template <typename... Args>
	static void DLogF(const std::string_view& message, Severity sev, Args... args);
	template <typename... Args>
	static void DLogF(const std::string& message, Severity sev, Args... args);
	template <typename... Args>
	static void DLogF(const char* message, Severity sev, Args... args);

public:
	virtual void log(const std::string_view& message, Severity sev) const = 0;
	virtual void log(const std::string& message, Severity sev) const = 0;
	virtual void log(const char* message, Severity sev) const = 0;
	virtual void logf(const std::string_view& message, Severity sev) const = 0;
	virtual void logf(const std::string& message, Severity sev) const = 0;
	virtual void logf(const char* message, Severity sev) const = 0;

	virtual void dlog(const std::string_view& message, Severity sev) const = 0;
	virtual void dlog(const std::string& message, Severity sev) const = 0;
	virtual void dlog(const char* message, Severity sev) const = 0;
	virtual void dlogf(const std::string_view& message, Severity sev) const = 0;
	virtual void dlogf(const std::string& message, Severity sev) const = 0;
	virtual void dlogf(const char* message, Severity sev) const = 0;

	virtual void logf(const std::string_view& message, Severity sev, const std::tuple<std::any>& tuple) const = 0;
	virtual void logf(const std::string& message, Severity sev, const std::tuple<std::any>& tuple) const = 0;
	virtual void logf(const char* message, Severity sev, const std::tuple<std::any>& tuple) const = 0;
	virtual void dlogf(const std::string_view& message, Severity sev, const std::tuple<std::any>& tuple) const = 0;
	virtual void dlogf(const std::string& message, Severity sev, const std::tuple<std::any>& tuple) const = 0;
	virtual void dlogf(const char* message, Severity sev, const std::tuple<std::any>& tuple) const = 0;

private:
	static std::unique_ptr<Logger> s_Logger;
};

// Template definitions are necessary in headers ig
template <typename ... Args>
void Logger::LogF(const std::string_view& message, Severity sev, Args... args)
{
	s_Logger->logf(message, sev, std::make_tuple(args...));
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
}

template <typename ... Args>
void Logger::LogF(const std::string& message, Severity sev, Args... args)
{
	s_Logger->logf(message, sev, std::make_tuple(args...));
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
}

template <typename ... Args>
void Logger::LogF(const char* message, Severity sev, Args... args)
{
	s_Logger->logf(message, sev, std::make_tuple(args...));
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
}

template <typename ... Args>
void Logger::DLogF(const std::string_view& message, Severity sev, Args... args)
{
	s_Logger->dlogf(message, sev, std::make_tuple(args...));
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
	assert(sev != Severity::WARN);
}

template <typename ... Args>
void Logger::DLogF(const std::string& message, Severity sev, Args... args)
{
	s_Logger->dlogf(message, sev, std::make_tuple(args...));
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
	assert(sev != Severity::WARN);
}

template <typename ... Args>
void Logger::DLogF(const char* message, Severity sev, Args... args)
{
	s_Logger->dlogf(message, sev, std::make_tuple(args...));
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
	assert(sev != Severity::WARN);
}