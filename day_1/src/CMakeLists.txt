add_library(Day1
    Day1Solver.cpp
)

add_executable(Solver main.cpp)
target_link_libraries(Solver PRIVATE Day1)