#include "memory.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>

bool SysTrace::Memory::GetMemoryUsage(SysTrace::MemoryInfo &infoOutput)
{
    // Example of "/proc/meminfo"
    // MemTotal:       16329928 kB
    // MemFree:         8593208 kB
    // MemAvailable:    9601144 kB
    // Buffers:          365416 kB
    // Cached:          3120884 kB
    std::ifstream file("/proc/meminfo");
    if (!file.is_open())
    {
        std::cerr << "Fail to open /proc/meminfo" << std::endl;
        return false;
    }
    std::string line;
    while (std::getline(file, line))
    {
        unsigned long long memTotalKB, memAvailableKB;
        if (TryGetMemTotal(line, memTotalKB))
        {
            infoOutput.SetMemTotal(memTotalKB << 10);
        }
        else if (TryGetMemAvailable(line, memAvailableKB))
        {
            infoOutput.SetMemAvailable(memAvailableKB << 10);
        }
    }
    file.close();
    return true;
}

bool SysTrace::Memory::TryGetMemTotal(const std::string &line, unsigned long long &outputKB)
{
    std::string fieldName, unitName;
    unsigned long long amount;
    Parse(line, fieldName, amount, unitName);
    if (fieldName == "MemTotal:")
    {
        outputKB = amount;
        return true;
    }
    return false;
}

bool SysTrace::Memory::TryGetMemAvailable(const std::string &line, unsigned long long &outputKB)
{
    std::string fieldName, unitName;
    unsigned long long amount;
    Parse(line, fieldName, amount, unitName);
    if (fieldName == "MemAvailable:")
    {
        outputKB = amount;
        return true;
    }
    return false;
}

void SysTrace::Memory::Parse(const std::string &line, std::string &fieldName, unsigned long long &amount, std::string &unitName)
{
    std::istringstream iss(line);
    iss >> fieldName >> amount >> unitName;
}
