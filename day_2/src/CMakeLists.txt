add_library(Day2
    ${CMAKE_CURRENT_SOURCE_DIR}/../../common/Solver.cpp
    Day2Solver.cpp
)

add_executable(Solver main.cpp)
target_link_libraries(Solver PRIVATE Day2)