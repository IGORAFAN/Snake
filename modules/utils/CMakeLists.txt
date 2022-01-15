cmake_minimum_required(VERSION 3.16)

project(utils LANGUAGES CXX)

find_package(Threads REQUIRED)

Set(${PROJECT_NAME}_HEADERS
        include/RandomGenerator.h
        include/RenderManager.h
        include/KeyboardManager.h
        include/ThreadManager.h
        include/Types.h
        )

Set(${PROJECT_NAME}_SOURCES
        source/RandomGenerator.cpp
        source/RenderManager.cpp
        source/KeyboardManager.cpp
        source/Type.cpp
        )

add_library(${PROJECT_NAME}
        ${${PROJECT_NAME}_HEADERS}
        ${${PROJECT_NAME}_SOURCES}
        )

add_library(snake::utils ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} Threads::Threads)

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

