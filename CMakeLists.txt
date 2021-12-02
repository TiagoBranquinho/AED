cmake_minimum_required(VERSION 3.20)
project(ProjetoAeroporto)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjetoAeroporto main.cpp Plane.cpp Plane.h Flight.cpp Flight.h Baggage.cpp Baggage.h Date.cpp Date.h tests.cpp Service.cpp Service.h)
