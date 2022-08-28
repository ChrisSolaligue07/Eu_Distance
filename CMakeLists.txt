cmake_minimum_required(VERSION 3.23)
project(Eu_Cluster)

set(CMAKE_CXX_STANDARD 23)

add_executable(Eu_Cluster main.cpp src/ConvertDm.h src/CreateData.h src/EU_distance.h src/FrecuencyData.h src/csv_rw.h)
