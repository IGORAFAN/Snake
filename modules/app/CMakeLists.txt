cmake_minimum_required(VERSION 3.20)

project(app LANGUAGES CXX)

set(${PROJECT_NAME}_HEADERS
        include/Field.h
        include/Game.h
        include/Snake.h
        )

set(${PROJECT_NAME}_SOURCES
        source/Field.cpp
        source/Game.cpp
        source/Main.cpp
        source/Snake.cpp
        )

add_executable(${PROJECT_NAME}
        ${${PROJECT_NAME}_HEADERS}
        ${${PROJECT_NAME}_SOURCES}
        )

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
