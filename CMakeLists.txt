cmake_minimum_required(VERSION 3.7.0 FATAL_ERROR)
project(8-Puzzle_Solver)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake-modules")

# ENABLE DEBUG
add_definitions(-DDEBUG)

# FIND MEMANCPP
find_package(MEMANCPP REQUIRED)
IF (NOT MEMANCPP_FOUND)
    message(FATAL_ERROR "MEMANCPP not find!")
ENDIF()

# INCLUDE DIRECTORIES
include_directories(src/puzzle src/external ${MEMANCPP_INCLUDE_DIR})

# SOURCE FILES
set(CORE_MAIN_FILE src/main.cpp)
file(GLOB_RECURSE CORE_HEADER_FILES src/puzzle/*)

# ADD EXEC AND LINK LIBS
add_executable(run ${MEMANCPP_FILES} ${CORE_HEADER_FILES} ${CORE_MAIN_FILE})
