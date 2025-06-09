#pragma once
#include "MemoryUnit.h"

namespace SysTrace
{
    /// @brief Memory information structure.
    struct MemoryInfo
    {
        /// @brief Get the total memory size.
        /// @param unit The unit in which to return the memory size.
        /// @return The total memory size in the specified unit.
        double GetMemTotal(MemoryUnit unit);

        /// @brief Set the total memory size.
        /// @param memTotalBytes The total memory size in bytes.
        void SetMemTotal(unsigned long long memTotalBytes);

        /// @brief Get the available memory size.
        /// @param unit The unit in which to return the memory size.
        /// @return The available memory size in the specified unit.
        double GetMemAvailable(MemoryUnit unit);

        /// @brief Set the available memory size.
        /// @param memAvailableBytes The available memory size in bytes.
        void SetMemAvailable(unsigned long long memAvailableBytes);

        /// @brief Get the used memory size. Calculated as total - available.
        /// @param unit The unit in which to return the memory size.
        /// @return The used memory size in the specified unit.
        double GetMemUsed(MemoryUnit unit);

    private:
        /// @brief Convert memory size from bytes to the specified unit.
        /// @param bytes The size in bytes.
        /// @param unit The unit to convert to.
        /// @return The memory size in the specified unit.
        double ToUnit(unsigned long long bytes, MemoryUnit unit);

        /// @brief Total memory size in bytes.
        unsigned long long _memTotalByte{0};

        /// @brief Available memory size in bytes.
        unsigned long long _memAvailableByte{0};
    };
}