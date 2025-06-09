#include "MemoryInfo.h"

double SysTrace::MemoryInfo::GetMemTotal(MemoryUnit unit)
{
    return ToUnit(_memTotalByte, unit);
}

void SysTrace::MemoryInfo::SetMemTotal(unsigned long long memTotalBytes)
{
    _memTotalByte = memTotalBytes;
}

double SysTrace::MemoryInfo::GetMemAvailable(MemoryUnit unit)
{
    return ToUnit(_memAvailableByte, unit);
}

void SysTrace::MemoryInfo::SetMemAvailable(unsigned long long memAvailableBytes)
{
    _memAvailableByte = memAvailableBytes;
}

double SysTrace::MemoryInfo::GetMemUsed(MemoryUnit unit)
{
    return ToUnit(_memTotalByte, unit) - ToUnit(_memAvailableByte, unit);
}

double SysTrace::MemoryInfo::ToUnit(unsigned long long bytes, MemoryUnit unit)
{
    switch (unit)
    {
    case SysTrace::MemoryUnit::KB:
        return (double)(bytes >> 10);
    case SysTrace::MemoryUnit::MB:
        return (double)(bytes >> 20);
    case SysTrace::MemoryUnit::GB:
        return (double)(bytes >> 30);

    default:
        break;
    }
    return bytes;
}
