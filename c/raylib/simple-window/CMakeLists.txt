cmake_minimum_required(VERSION 3.10)
project(simple_window C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

add_executable(simple_window src/main.c)

target_link_libraries(simple_window PRIVATE raylib)
