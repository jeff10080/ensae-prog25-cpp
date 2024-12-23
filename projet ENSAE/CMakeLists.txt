cmake_minimum_required(VERSION 3.29)
project(projet_ENSAE)

set(CMAKE_CXX_STANDARD 20)

add_executable(projet_ENSAE main.cpp
        Option.cpp
        Option.h
        BlackScholesModel.cpp
        BlackScholesModel.h
        MonteCarloPricer.cpp
        MonteCarloPricer.h)
