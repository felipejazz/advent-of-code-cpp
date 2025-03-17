add_executable(TestSolver TestSolver.cpp)
target_include_directories(TestSolver PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(TestSolver PRIVATE Day1)


add_test(NAME TestSolver COMMAND TestSolver)
