cmake_minimum_required(VERSION 3.16)
project(Vehicules CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app
    src/main.cpp
    src/Vehicule.cpp
    src/Voiture.cpp
    src/Camion.cpp
)

target_compile_options(app PRIVATE -Wall -Wextra)
