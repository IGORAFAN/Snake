cmake_minimum_required(VERSION 3.16)

project(app LANGUAGES CXX)

find_package(Threads REQUIRED)

set(${PROJECT_NAME}_HEADERS
        include/Constants.h
        include/Enums.h
        include/Field.h
        include/Food.h
        include/Game.h
        include/Snake.h
        include/Score.h
        include/Wall.h
        )

set(${PROJECT_NAME}_SOURCES
        source/Field.cpp
        source/Food.cpp
        source/Game.cpp
        source/Main.cpp
        source/Snake.cpp
        source/Score.cpp
        source/Wall.cpp
        )

add_executable(${PROJECT_NAME}
        ${${PROJECT_NAME}_HEADERS}
        ${${PROJECT_NAME}_SOURCES}
        )

target_link_libraries(${PROJECT_NAME}
        snake::utils
        Threads::Threads
        )

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_compile_options(${PROJECT_NAME}
        PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:
        /MP /W3 /Zf
        $<$<CONFIG:Debug>:/MTd>
        $<$<CONFIG:Release>:/MT>>
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall -Wextra -Werror -pthread -lpthread -Wpedantic -pedantic-errors -pipe>
        )