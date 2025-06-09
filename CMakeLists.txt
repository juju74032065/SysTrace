cmake_minimum_required(VERSION 3.10)
project(procmon-lite)

set(CMAKE_CXX_STANDARD 17)

add_executable(procmon-lite
    src/main.cpp
    src/cpu.cpp
    src/memory.cpp
    model/MemoryInfo.cpp
)
