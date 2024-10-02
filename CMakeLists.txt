cmake_minimum_required(VERSION 3.29)
project(lebron C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(lib)

add_executable(lebron src/main.c)
target_link_libraries(lebron PUBLIC liblebron)