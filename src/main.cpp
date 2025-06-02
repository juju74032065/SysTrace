// main.cpp
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include "cpu.h"

int main()
{
    while (true)
    {
        float usage = procmon::GetCPUUsage();
        std::cout << "CPU Usage: " << std::fixed << std::setprecision(2) << usage << "%" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
