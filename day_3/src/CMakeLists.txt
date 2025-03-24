add_library(Day3
    ${CMAKE_CURRENT_SOURCE_DIR}/../../common/Solver.cpp
    Day3Solver.cpp
    main.cpp
)

add_executable(Solver main.cpp)
target_link_libraries(Solver PRIVATE Day3)