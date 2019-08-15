cmake_minimum_required (VERSION 3.0)

# include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE SOURCES *.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})