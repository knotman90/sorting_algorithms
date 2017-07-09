cmake_minimum_required(VERSION 2.8)

project(SORTING)

set(EXTRA_WARNING_GNU "-march=native -Wextra -Wdisabled-optimization  -Wunsafe-loop-optimizations -funsafe-loop-optimizations -Wshadow -Wpointer-arith -Wcast-qual -Wunreachable-code ")
set (CMAKE_CXX_STANDARD 14)
if ( CMAKE_COMPILER_IS_GNUCC  OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall ${EXTRA_WARNING_GNU}")
endif ( CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif ( MSVC )

find_package(GTest REQUIRED)

#global include for all targets
include_directories(sorting_tests source)

#tests
add_executable(sorting_tests tests/sorttest.cpp)
target_include_directories(sorting_tests PUBLIC ${GTEST_INCLUDE_DIRS})
target_include_directories(sorting_tests PUBLIC tests)
target_link_libraries(sorting_tests pthread ${GTEST_BOTH_LIBRARIES})

#benchmark
add_executable(sorting_benchmark benchmark/sorting_benchmark.cpp)
target_include_directories(sorting_benchmark PUBLIC benchmark)
target_link_libraries(sorting_benchmark pthread -lbenchmark)