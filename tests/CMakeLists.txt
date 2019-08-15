cmake_minimum_required (VERSION 3.0)

project (images_tests)

include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB_RECURSE TEST_SOURCES *.cpp)

set(SOURCES ${CMAKE_SOURCE_DIR}/src/images/Image.cpp
            ${CMAKE_SOURCE_DIR}/src/images/ImagePpm.cpp
            ${CMAKE_SOURCE_DIR}/src/images/utils/Pixel.cpp
            ${CMAKE_SOURCE_DIR}/src/images/utils/RawPixel.cpp
            ${CMAKE_SOURCE_DIR}/src/algorithms/Masking.cpp
            ${CMAKE_SOURCE_DIR}/src/algorithms/Algorithm.cpp)

add_executable(${PROJECT_NAME} ${TEST_SOURCES} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)

add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
)
