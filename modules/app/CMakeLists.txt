cmake_minimum_required(VERSION 3.16)

project(app LANGUAGES CXX)

set(${PROJECT_NAME}_HEADERS
        include/Constants.h
        include/Enums.h
        include/Field.h
        include/Food.h
        include/Game.h
        include/Snake.h
        )

set(${PROJECT_NAME}_SOURCES
        source/Field.cpp
        source/Food.cpp
        source/Game.cpp
        source/Main.cpp
        source/Snake.cpp
        )

add_executable(${PROJECT_NAME}
        ${${PROJECT_NAME}_HEADERS}
        ${${PROJECT_NAME}_SOURCES}
        )

target_link_libraries(${PROJECT_NAME} utils)