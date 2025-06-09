#include "cpu.h"
#include <fstream>
#include <thread>
#include <chrono>
#include <sstream>

long long SysTrace::CPU::GetIdleAccumulatedJiffy(const std::string &line)
{
    std::istringstream iss(line);
    std::string cpu;
    // Description of the first line in /proc/stat (aggregate statistics for all CPUs)
    // Following time are accumulated.
    // Field order:
    // user        - Time spent in user mode (normal processes, excluding nice time)
    // nice        - Time spent in user mode with low priority (processes with positive nice values)
    //                  These processes are "nice" because they give up CPU time to others.
    // system      - Time spent in kernel mode (running system processes and drivers)
    // idle        - Time spent doing nothing (CPU is idle)
    // iowait      - Time waiting for I/O operations to complete (e.g., disk or network I/O)
    // irq         - Time servicing hardware interrupts
    // softirq     - Time servicing software interrupts
    // steal       - Time stolen by other virtual machines (only applies in virtualized environments)
    // guest       - Time spent running a virtual CPU for guest operating systems
    // guest_nice  - Time spent running a nice guest (guest OS processes with positive nice values)
    long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    iss >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;
    return idle + iowait;
}
long long SysTrace::CPU::GetTotalAccumulatedJiffy(const std::string &line)
{
    std::istringstream iss(line);
    std::string cpu;
    long long total = 0, value;
    iss >> cpu;
    while (iss >> value)
        total += value;
    return total;
}

SysTrace::CPUInfo SysTrace::CPU::GetCPUUsage()
{
    std::ifstream file("/proc/stat");
    std::string line1;
    std::getline(file, line1);
    long long idle1 = GetIdleAccumulatedJiffy(line1);
    long long total1 = GetTotalAccumulatedJiffy(line1);
    file.close();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    file.open("/proc/stat");
    std::string line2;
    std::getline(file, line2);
    long long idle2 = GetIdleAccumulatedJiffy(line2);
    long long total2 = GetTotalAccumulatedJiffy(line2);
    file.close();

    float idleDelta = idle2 - idle1;
    float totalDelta = total2 - total1;
    SysTrace::CPUInfo info = SysTrace::CPUInfo();
    info.Usage = 100.0f * (1.0f - idleDelta / totalDelta);
    return info;
}
