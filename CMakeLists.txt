cmake_minimum_required(VERSION 3.31)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 20)

add_executable(DesignPatterns main.cpp
        KeyBoard.cpp
        KeyBoard.h
        Builder.cpp
        Builder.h
        Factory.cpp
        Factory.h)
