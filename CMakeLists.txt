cmake_minimum_required(VERSION 3.0.0)
project(DataIO VERSION 0.1.0)

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")

include(CTest)
enable_testing()

add_executable(DataIO main.cpp Exception.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
