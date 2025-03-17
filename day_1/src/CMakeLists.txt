add_library(Day1
    ${CMAKE_SOURCE_DIR}/src/Solver.cpp
)

target_include_directories(Day1 PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(Solver ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_link_libraries(Solver PRIVATE Day1)
