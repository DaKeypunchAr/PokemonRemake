#include "Logger.hpp"
#include "ConsoleLogger.hpp"

void Logger::Initialize()
{
	s_Logger = std::make_unique<ConsoleLogger>();
}
void Logger::Destroy()
{
	s_Logger.reset();
}

void Logger::Log(const std::string_view& message, Severity sev)
{
	s_Logger->log(message, sev);
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
}

void Logger::Log(const std::string& message, Severity sev)
{
	s_Logger->log(message, sev);
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
}

void Logger::Log(const char* message, Severity sev)
{
	s_Logger->log(message, sev);
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
}

void Logger::LogF(const std::string_view& message, Severity sev)
{
	s_Logger->logf(message, sev);
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
}

void Logger::LogF(const std::string& message, Severity sev)
{
	s_Logger->logf(message, sev);
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
}

void Logger::LogF(const char* message, Severity sev)
{
	s_Logger->logf(message, sev);
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
}

void Logger::DLog(const std::string_view& message, Severity sev)
{
	s_Logger->dlog(message, sev);
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
	assert(sev != Severity::WARN);
}

void Logger::DLog(const std::string& message, Severity sev)
{
	s_Logger->dlog(message, sev);
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
	assert(sev != Severity::WARN);
}

void Logger::DLog(const char* message, Severity sev)
{
	s_Logger->dlog(message, sev);
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
	assert(sev != Severity::WARN);
}

void Logger::DLogF(const std::string_view& message, Severity sev)
{
	s_Logger->dlogf(message, sev);
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
	assert(sev != Severity::WARN);
}

void Logger::DLogF(const std::string& message, Severity sev)
{
	s_Logger->dlogf(message, sev);
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
	assert(sev != Severity::WARN);
}

void Logger::DLogF(const char* message, Severity sev)
{
	s_Logger->dlogf(message, sev);
	if (sev == Severity::ERR) exit(EXIT_FAILURE);
	assert(sev != Severity::WARN);
}

std::unique_ptr<Logger> Logger::s_Logger;