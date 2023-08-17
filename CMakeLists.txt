cmake_minimum_required(VERSION 3.20)
set(PROJECT_NAME cppTemplate)
project(${PROJECT_NAME} VERSION 0.1.0)

# Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILE_FEATURES OFF)

# set CMAKE_CXX_FLAGS
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "-O3 -Wall -Werror")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "-g -O0 -Wall -Werror")
endif()
message(STATUS "CXX FLAGS: ${CMAKE_CXX_FLAGS}")

# src
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cc src/*.cpp inc/*.h)
# add_library(${PROJECT_NAME} SHARED ${srcs})
add_executable(${PROJECT_NAME} ${srcs})
target_link_libraries(${PROJECT_NAME} PUBLIC pthread)
target_include_directories(${PROJECT_NAME} PUBLIC inc)

# sub
# add_subdirectory()

# test
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Enable test")
    add_subdirectory(test)
endif()
