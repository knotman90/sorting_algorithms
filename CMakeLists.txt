cmake_minimum_required(VERSION 2.8)

project(SORTING)

set (CMAKE_CXX_STANDARD 14)
if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
endif ( CMAKE_COMPILER_IS_GNUCC )
if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif ( MSVC )


find_package(GTest REQUIRED)


include_directories(${GTEST_INCLUDE_DIRS})
include_directories(source tests)


add_executable(sorting_tests tests/sorttest.cpp)
target_link_libraries(sorting_tests pthread ${GTEST_BOTH_LIBRARIES})