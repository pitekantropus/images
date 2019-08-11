cmake_minimum_required (VERSION 3.0)

project (images)

set(CMAKE_CXX_STANDARD 14)

include_directories (${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE IMAGES_SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${IMAGES_SOURCES})
