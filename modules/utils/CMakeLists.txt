cmake_minimum_required(VERSION 3.16)

project(utils LANGUAGES CXX)

Set(${PROJECT_NAME}_HEADERS
        include/RandomGenerator.h
        include/KeyboardManager.h
        include/Types.h
        )

Set(${PROJECT_NAME}_SOURCES
        source/RandomGenerator.cpp
        source/KeyboardManager.cpp
        )

add_library(${PROJECT_NAME}
        ${${PROJECT_NAME}_HEADERS}
        ${${PROJECT_NAME}_SOURCES}
        )