cmake_minimum_required(VERSION 3.16)
project(Parking CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app
    src/main.cpp
    src/Vehicule.cpp            # etape 1
    src/TypesVehicule.cpp       # etape 1
    src/Place.cpp
    src/Parking.cpp
    src/VoitureElectrique.cpp
)

target_compile_options(app PRIVATE -Wall -Wextra)
