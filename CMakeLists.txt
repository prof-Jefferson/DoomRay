cmake_minimum_required(VERSION 3.16)
project(DoomRay LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

add_executable(DoomRay src/main.cpp)
target_link_libraries(DoomRay PRIVATE sfml-graphics sfml-window sfml-system)
