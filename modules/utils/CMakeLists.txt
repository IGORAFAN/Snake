cmake_minimum_required(VERSION 3.20)

project(utils LANGUAGES CXX)

Set(${PROJECT_NAME}_HEADERS
        include/RandomGenerator.h
        )

Set(${PROJECT_NAME}_SOURCES
        source/RandomGenerator.cpp
        )

add_executable(${PROJECT_NAME}
        ${${PROJECT_NAME}_HEADERS}
        ${${PROJECT_NAME}_SOURCES}
        )