cmake_minimum_required(VERSION 3.16)
project(DoomRay LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

add_executable(DoomRay
    src/main.cpp
    src/app/App.cpp
    src/ui/TextPanel.cpp
    src/ui/Renderer2D.cpp
    src/core/Map.cpp
    src/core/Player.cpp
)

# adiciona os diretórios de include
target_include_directories(DoomRay PRIVATE
    src/app
    src/ui
    src/core
)

target_link_libraries(DoomRay PRIVATE sfml-graphics sfml-window sfml-system)
