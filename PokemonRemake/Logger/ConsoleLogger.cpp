#include "ConsoleLogger.hpp"
#include <iostream>
#include <tuple>
#include <any>
#include <sstream>

// TODO: ChatGPT CODE the whole file is copy pasted!!!!! Read, Understand, Confirm, Improve this shit

// ANSI color codes for terminal output
namespace Color
{
	const std::string RESET = "\033[0m";
	const std::string RED = "\033[31m"; // Error
	const std::string YELLOW = "\033[33m"; // Warning
	const std::string GREEN = "\033[32m"; // Info
	const std::string BLUE = "\033[34m"; // Debug
}

// Helper function to map severity to color
std::string colorForSeverity(Logger::Severity sev)
{
	switch (sev)
	{
		case Logger::Severity::INFO: return Color::GREEN;
		case Logger::Severity::WARN: return Color::YELLOW;
		case Logger::Severity::ERR: return Color::RED;
		default: return Color::RESET;
	}
}

// Helper function to map severity to string
std::string severityToStr(Logger::Severity sev)
{
	switch (sev)
	{
		case Logger::Severity::INFO: return "INFO";
		case Logger::Severity::WARN: return "WARN";
		case Logger::Severity::ERR: return "ERROR";
		default: return "UNKNOWN";
	}
}

// Helper function to format the message using the provided format
std::string formatMessage(const char* message, const std::tuple<std::any>& tuple)
{
	std::ostringstream oss;
	std::string formattedMessage = message;

	size_t index = 0;
	while (formattedMessage.find('%') != std::string::npos)
	{
		if (index < std::tuple_size_v<std::remove_reference_t<decltype(tuple)>>)
		{
			const std::any& value = std::get<0>(tuple);
			std::string placeholder;

			if (formattedMessage.find("%d") != std::string::npos && value.type() == typeid(int))
			{
				placeholder = "%d";
				oss << std::any_cast<int>(value);
			}
			else if (formattedMessage.find("%f") != std::string::npos && value.type() == typeid(double))
			{
				placeholder = "%f";
				oss << std::any_cast<double>(value);
			}
			else if (formattedMessage.find("%s") != std::string::npos && value.type() == typeid(std::string))
			{
				placeholder = "%s";
				oss << std::any_cast<std::string>(value);
			}
			else if (formattedMessage.find("%%") != std::string::npos)
			{
				placeholder = "%%";
				oss << "%";
			}

			size_t pos = formattedMessage.find(placeholder);
			formattedMessage.replace(pos, placeholder.length(), oss.str());
			oss.str("");
			index++;
		}
		else
		{
			break;
		}
	}
	return formattedMessage;
}

// ConsoleLogger function implementations
ConsoleLogger::ConsoleLogger()
	: Logger()
{
	ConsoleLogger::dlog("Initialized ConsoleLogger!", Severity::INFO);
}

ConsoleLogger::~ConsoleLogger()
{
	ConsoleLogger::dlog("Destroyed ConsoleLogger!", Severity::INFO);
}

void ConsoleLogger::dlog(const char* message, Severity sev) const
{
	std::cout << colorForSeverity(sev) << "[DEBUG] " << severityToStr(sev) << ": " << message << Color::RESET << std::endl;
}

void ConsoleLogger::dlog(const std::string& message, Severity sev) const
{
	dlog(message.c_str(), sev);
}

void ConsoleLogger::dlog(const std::string_view& message, Severity sev) const
{
	dlog(message.data(), sev);
}

void ConsoleLogger::dlogf(const char* message, Severity sev, const std::tuple<std::any>& tuple) const
{
	std::cout << colorForSeverity(sev) << "[DEBUG] " << severityToStr(sev) << ": " << formatMessage(message, tuple) << Color::RESET << std::endl;
}

void ConsoleLogger::dlogf(const std::string& message, Severity sev, const std::tuple<std::any>& tuple) const
{
	dlogf(message.c_str(), sev, tuple);
}

void ConsoleLogger::dlogf(const std::string_view& message, Severity sev, const std::tuple<std::any>& tuple) const
{
	dlogf(message.data(), sev, tuple);
}

void ConsoleLogger::dlogf(const char* message, Severity sev) const
{
	std::cout << colorForSeverity(sev) << "[DEBUG] " << severityToStr(sev) << ": " << message << Color::RESET << std::endl;
}

void ConsoleLogger::dlogf(const std::string& message, Severity sev) const
{
	dlogf(message.c_str(), sev);
}

void ConsoleLogger::dlogf(const std::string_view& message, Severity sev) const
{
	dlogf(message.data(), sev);
}

void ConsoleLogger::log(const std::string_view& message, Severity sev) const
{
	std::cout << colorForSeverity(sev) << "[" << severityToStr(sev) << "] " << message << Color::RESET << std::endl;
}

void ConsoleLogger::log(const std::string& message, Severity sev) const
{
	log(message.c_str(), sev);
}

void ConsoleLogger::log(const char* message, Severity sev) const
{
	std::cout << colorForSeverity(sev) << "[" << severityToStr(sev) << "] " << message << Color::RESET << std::endl;
}

void ConsoleLogger::logf(const char* message, Severity sev, const std::tuple<std::any>& tuple) const
{
	std::cout << colorForSeverity(sev) << "[" << severityToStr(sev) << "] " << formatMessage(message, tuple) << Color::RESET << std::endl;
}

void ConsoleLogger::logf(const std::string& message, Severity sev, const std::tuple<std::any>& tuple) const
{
	logf(message.c_str(), sev, tuple);
}

void ConsoleLogger::logf(const std::string_view& message, Severity sev, const std::tuple<std::any>& tuple) const
{
	logf(message.data(), sev, tuple);
}

void ConsoleLogger::logf(const char* message, Severity sev) const
{
	std::cout << colorForSeverity(sev) << "[" << severityToStr(sev) << "] " << message << Color::RESET << std::endl;
}

void ConsoleLogger::logf(const std::string& message, Severity sev) const
{
	logf(message.c_str(), sev);
}

void ConsoleLogger::logf(const std::string_view& message, Severity sev) const
{
	logf(message.data(), sev);
}