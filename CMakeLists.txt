cmake_minimum_required(VERSION 3.20)
project(ProjetoAeroporto)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjetoAeroporto main.cpp src/Plane.cpp include/Plane.h src/Flight.cpp include/Flight.h src/Baggage.cpp include/Baggage.h src/Date.cpp include/Date.h src/Service.cpp include/Service.h src/Person.cpp include/Person.h src/Passenger.cpp include/Passenger.h src/Employee.cpp include/Employee.h src/GroundTransportation.cpp include/GroundTransportation.h include/bst.h src/Schedule.cpp include/Schedule.h src/Airport.cpp include/Airport.h src/Airline.cpp include/Airline.h src/TransportCart.cpp include/TransportCart.h tests/ScheduleTest.cpp tests/FlightTest.cpp src/TransportationLocals.cpp include/TransportationLocals.h tests/AirportTest.cpp tests/PlaneTest.cpp)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

target_link_libraries(ProjetoAeroporto gtest gtest_main)