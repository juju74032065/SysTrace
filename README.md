# SysTrace

**SysTrace** is a lightweight, multi-threaded system monitoring tool written in C++ for Linux (tested on WSL + Ubuntu).  
It currently monitors **CPU usage** in real time and is designed to be modular for future extensions such as memory monitoring, logging, and a terminal UI.

---

## 🧠 Features

- 🔍 Reads CPU statistics from `/proc/stat`
- 📊 Displays CPU usage (user, system, idle)
- 🔄 Updates every second
- 💡 Designed with modular, multithreaded architecture
- 🛠️ Written in modern C++17 with clear code structure

---

## 🖥 Preview

```bash
[CPU] CPU Usage: 1.00%
[MEM] Used: 1.00GB / 15.00GB (6.7%)
[CPU] CPU Usage: 0.25%
[MEM] Used: 1.00GB / 15.00GB (6.7%)
```

---

## 📁 Project Structure

SysTrace/
├── src/
│   ├── main.cpp           # Entry point
│   ├── cpu.cpp            # CPU monitoring logic
│   └── cpu.h              # Shared utility functions
├── CMakeLists.txt         # Build configuration
└── README.md              # Project documentation

---

## ⚙️ Build Instructions

### 🔧 Prerequisites

- Linux or WSL with Ubuntu

- GCC / g++

- Make

### 🧪 Build & Run

```bash
# Clone the repository
git clone https://github.com/juju74032065/SysTrace
cd SysTrace

# Build the project
make

# Run the executable
./systrace

```

## 🛣️ Roadmap (Feature Checklist)

### ✅ Implemented
- [x] CPU usage monitor via `/proc/stat`
- [x] Modular project structure with headers and source files
- [x] Makefile for easy building
- [x] Git/GitHub integration
- [x] WSL + Ubuntu setup tested

### 🧩 In Progress / Planned
- [ ] Memory usage monitor via `/proc/meminfo`
- [ ] Multithreaded design (CPU and Memory in separate threads)
- [ ] Periodic logging to a file
- [ ] ncurses terminal UI
- [ ] Command-line arguments (e.g. update interval, log path)
- [ ] Export output in JSON format
- [ ] Unit tests (Google Test or Catch2)
- [ ] GitHub Actions (CI/CD)

## 📜 License
MIT License. Feel free to use, modify, and share.

## 👨‍💻 Author
Developed by Sam — Software Engineer focused on systems and tools development.
