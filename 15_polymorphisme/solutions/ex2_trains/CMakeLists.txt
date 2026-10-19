cmake_minimum_required(VERSION 3.16)
project(Trains CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app
    src/main.cpp
    src/Gare.cpp
    src/Train.cpp
    src/TypesTrain.cpp
    src/TrainDeNuit.cpp
)

target_compile_options(app PRIVATE -Wall -Wextra)
