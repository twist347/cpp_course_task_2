cmake_minimum_required(VERSION 3.20)

project(cpp-course-task2)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(CMAKE_C_STANDARD 11)

set(CRITERION_DIR "${CMAKE_SOURCE_DIR}/external/criterion-2.4.2")

add_library(my_sorts STATIC src/my_sorts.c)
target_include_directories(my_sorts PUBLIC include)
target_compile_options(my_sorts PRIVATE -Wall -Wextra -pedantic -Werror)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address,leak,undefined")

enable_testing()
add_subdirectory(test)
