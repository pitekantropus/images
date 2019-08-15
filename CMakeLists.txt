cmake_minimum_required (VERSION 3.0)

project (images)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
if(TESTS)
    add_subdirectory(tests)
endif()

