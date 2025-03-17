add_library(Day1
    ${CMAKE_CURRENT_SOURCE_DIR}/../../common/Solver.cpp
    Day1Solver.cpp
)

add_executable(Solver main.cpp)
target_link_libraries(Solver PRIVATE Day1)