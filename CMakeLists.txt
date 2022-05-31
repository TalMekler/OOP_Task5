cmake_minimum_required(VERSION 3.22)
project(assignment)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment
        Animal.cpp
        Animal.h
        Birds.cpp
        Birds.h
        Fish.cpp
        Fish.h
        Flamingo.cpp
        Flamingo.h
        GoldFish.cpp
        GoldFish.h
        Horse.cpp
        Horse.h
        MainTrain.cpp
        Mammals.cpp
        Mammals.h
        MammalsFish.cpp
        MammalsFish.h
        Mermaid.cpp
        Mermaid.h
        Zoo.cpp
        Zoo.h)
