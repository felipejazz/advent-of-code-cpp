add_library(Day2
    Day2Solver.cpp
)

add_executable(Solver main.cpp)
target_link_libraries(Solver PRIVATE Day2)