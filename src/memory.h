#pragma once
#include <string>
#include "../model/MemoryInfo.h"

namespace SysTrace
{
    class Memory;
}

/// @brief Module to get memory info.
class SysTrace::Memory
{
public:
    /// @brief Retrieve memory usage information from the system.
    /// This function reads from the "/proc/meminfo" file and parses the total and available memory.
    /// @param infoOutput Reference to a MemoryInfo object that will be populated with memory data.
    /// @return true if memory information was successfully retrieved and parsed; false otherwise.
    bool GetMemoryUsage(SysTrace::MemoryInfo &infoOutput);

private:
    /// @brief Attempt to parse the total memory size from a single line of "/proc/meminfo".
    /// @param line A line from "/proc/meminfo".
    /// @param outputKB Parsed memory size in kilobytes.
    /// @return true if the line contains "MemTotal:" and the value was successfully parsed; false otherwise.
    bool TryGetMemTotal(const std::string &line, unsigned long long &outputKB);

    /// @brief Attempt to parse the available memory size from a single line of "/proc/meminfo".
    /// @param line A line from "/proc/meminfo".
    /// @param outputKB Parsed memory size in kilobytes.
    /// @return true if the line contains "MemAvailable" and the value was successfully parsed; false otherwise.
    bool TryGetMemAvailable(const std::string &line, unsigned long long &outputKB);

    /// @brief Parse a line from "/proc/meminfo" into field name, amount, and unit.
    /// @param line The raw line from the file.
    /// @param fieldName Parsed field name (e.g., "MemTotal").
    /// @param amount Parsed numeric value (e.g., 32746836).
    /// @param unitName Parsed unit string (e.g., "kB").
    void Parse(const std::string &line, std::string &fieldName, unsigned long long &amount, std::string &unitName);
};