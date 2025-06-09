#pragma once

namespace SysTrace
{
    /// @brief CPU usage information.
    struct CPUInfo
    {
        /// @brief CPU usage as a percentage (0.0 to 100.0).
        float Usage{0.0};
    };
}