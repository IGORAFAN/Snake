cmake_minimum_required(VERSION 3.16)

project(Snake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(modules/app)
add_subdirectory(modules/utils)
