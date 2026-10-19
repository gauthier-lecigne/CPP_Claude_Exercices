cmake_minimum_required(VERSION 3.16)
project(Reseau CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app
    src/main.cpp
    src/Gare.cpp
    src/Ligne.cpp
    src/Reseau.cpp
)

target_compile_options(app PRIVATE -Wall -Wextra)
