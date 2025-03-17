# Advent of Code - C++ Solutions

This repository contains my solutions for [Advent of Code](https://adventofcode.com/) challenges implemented in C++.


## Repository Structure

Each day's challenge is organized in its own directory (e.g., `day_1`, `day_2`, etc.). A typical structure for a day's solution is as follows:

```bash
day_1/
├── CMakeLists.txt
├── include
│   └── Solver.hpp       # Header files for the solution
├── src
│   ├── CMakeLists.txt
│   ├── input
│   │   └── input.txt    # Challenge input file 
│   ├── main.cpp         # Entry point for the solution
│   └── Solver.cpp       # Implementation of the solution
└── tests
    ├── CMakeLists.txt
    ├── input
    │   └── input.txt    
    └── TestSolver.cpp   # Test cases using assert for validation

```
## How to Build and Test

For each day , you can compile and run tests by following these steps:

1. **Navigate** to the specific day’s directory (e.g., `queue/` or `stack/`).
2. **Enter** the `build` directory within that day, for example:

```bash 
cd day_x
mkdir build
cd build
```

Run CMake to generate the build files:
```bash
    cmake ..
```
Compile the project:
```bash
    make
 ```
Run the tests inside the build directory. Tests are located in ./tests/:
```bash
    ./tests/TestSolver
```
Run the main code inside the build directory. Tests are located in ./tests/:
```bash
    ./src/Solver
```

Repeat similar steps for any other day you want to build and test.
Navigational Guide

    <day_xs>/include: Headers for the specified day.
    <day_xs>/src: Source files for the specified day.
    <day_xs>/tests: Test files using assert statements.
    <day_xs>/build: Compiled artifacts are generated here after running cmake .. && make.


To build and run this project, you need:

    CMake (version >= 3.x)
    Make (or a compatible build system)
    A C++ compiler that supports C++11 (or higher)

