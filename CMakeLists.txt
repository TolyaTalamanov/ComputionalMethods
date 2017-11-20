cmake_minimum_required(VERSION 3.4)
project(ComputationalMethods)

set(CMAKE_CXX_STANDARD 14)
set(INCLUDE include/ComputionalMethods.h)
set(SOURCE src/GaussMethod.cpp src/GaussMethod.h
           src/KramerMethod.cpp src/KramerMethod.h
           src/SimpleIterationMethod.cpp
           src/SimpleIterationMethod.h
           src/SeidelMethod.cpp
           src/SeidelMethod.h src/UpperRelaxationMethod.cpp
           src/UpperRelaxationMethod.h src/ComputionalMethod.cpp)

set(SOURCE_FILES sample/main.cpp ${INCLUDE} ${SOURCE} )
add_executable(ComputationalMethods ${SOURCE_FILES})
add_library(ComputionalMethodsLib ${SOURCE_FILES})
