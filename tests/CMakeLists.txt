cmake_minimum_required (VERSION 3.0)

project (images_tests)

include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB_RECURSE TEST_SOURCES *.cpp)
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/*.cpp)

list(REMOVE_ITEM SOURCES ${CMAKE_SOURCE_DIR}/main.cpp)

add_executable(${PROJECT_NAME} ${TEST_SOURCES} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)

add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
)
