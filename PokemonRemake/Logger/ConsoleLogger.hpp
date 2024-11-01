#pragma once
#include "Logger.hpp"

class ConsoleLogger : public Logger
{
public:
	ConsoleLogger();
	~ConsoleLogger() override;

	void dlog(const char* message, Severity sev) const override;
	void dlog(const std::string& message, Severity sev) const override;
	void dlog(const std::string_view& message, Severity sev) const override;
	void dlogf(const char* message, Severity sev, const std::tuple<std::any>& tuple) const override;
	void dlogf(const std::string& message, Severity sev, const std::tuple<std::any>& tuple) const override;
	void dlogf(const std::string_view& message, Severity sev, const std::tuple<std::any>& tuple) const override;
	void dlogf(const char* message, Severity sev) const override;
	void dlogf(const std::string& message, Severity sev) const override;
	void dlogf(const std::string_view& message, Severity sev) const override;
	void log(const std::string_view& message, Severity sev) const override;
	void log(const std::string& message, Severity sev) const override;
	void log(const char* message, Severity sev) const override;
	void logf(const char* message, Severity sev, const std::tuple<std::any>& tuple) const override;
	void logf(const std::string& message, Severity sev, const std::tuple<std::any>& tuple) const override;
	void logf(const std::string_view& message, Severity sev, const std::tuple<std::any>& tuple) const override;
	void logf(const char* message, Severity sev) const override;
	void logf(const std::string& message, Severity sev) const override;
	void logf(const std::string_view& message, Severity sev) const override;
};