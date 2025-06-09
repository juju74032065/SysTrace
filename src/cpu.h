#pragma once
#include <string>
#include "../model/CPUInfo.h"

namespace SysTrace
{
    class CPU;
}

class SysTrace::CPU
{
public:
    /// @brief Compute the current CPU usage based on data from "/proc/stat".
    /// Usage = (TotalTime - IdleTime) / TotalTime
    /// @return A CPUInfo object containing the current CPU usage percentage.
    SysTrace::CPUInfo GetCPUUsage();

private:
    /// @brief Parse and compute the accumulated idle time from the first line of "/proc/stat".
    ///
    /// A "jiffy" is the unit of time used by the Linux kernel to measure CPU time.
    /// It represents one tick of the system timer. The duration of a jiffy depends on
    /// kernel settings—typically 1/100, 1/250, or 1/1000 of a second (e.g., 1 jiffy = 1 ms if using 1000 Hz).
    /// You can check the jiffy rate using: `getconf CLK_TCK`.
    ///
    /// @param line The first line of the "/proc/stat" file.
    /// @return Accumulated idle time in jiffies.
    static long long GetIdleAccumulatedJiffy(const std::string &line);

    /// @brief Parse and compute the accumulated total CPU time from the first line of "/proc/stat".
    /// @param line The first line of the "/proc/stat" file.
    /// @return Accumulated total CPU time in jiffies.
    static long long GetTotalAccumulatedJiffy(const std::string &line);
};