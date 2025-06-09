// main.cpp
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include "cpu.h"
#include "memory.h"

int main()
{
    while (true)
    {
        // Calculate cpu info
        auto cpuMonitor = SysTrace::CPU();
        auto cpuInfo = cpuMonitor.GetCPUUsage();
        std::cout << "[CPU] CPU Usage: " << std::fixed << std::setprecision(2) << cpuInfo.Usage << "%" << std::endl;

        // Calculate memory info
        auto memInfo = SysTrace::MemoryInfo();
        auto memoryMonitor = SysTrace::Memory();
        if (memoryMonitor.GetMemoryUsage(memInfo))
        {
            auto usedGB = memInfo.GetMemUsed(SysTrace::MemoryUnit::GB);
            auto totalGB = memInfo.GetMemTotal(SysTrace::MemoryUnit::GB);
            auto memUsage = 100.0 * usedGB / totalGB;
            std::cout << "[MEM] Used: " << std::fixed << std::setprecision(2) << usedGB << "GB / " << std::fixed << std::setprecision(2) << totalGB << "GB (" << std::fixed << std::setprecision(1) << memUsage << "%)"
                      << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
