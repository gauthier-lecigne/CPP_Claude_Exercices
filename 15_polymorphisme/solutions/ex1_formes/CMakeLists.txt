cmake_minimum_required(VERSION 3.16)
project(Formes CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app
    src/main.cpp
    src/Forme.cpp
    src/Cercle.cpp
    src/Rectangle.cpp
    src/Triangle.cpp
    src/Carre.cpp
    src/Hexagone.cpp
)

target_compile_options(app PRIVATE -Wall -Wextra)
