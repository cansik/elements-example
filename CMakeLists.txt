cmake_minimum_required(VERSION 3.16)
project(elements_example)

set(CMAKE_CXX_STANDARD 17)

# elements
set(ELEMENTS_ROOT ${PROJECT_SOURCE_DIR}/elements)
get_filename_component(ELEMENTS_ROOT "${ELEMENTS_ROOT}" ABSOLUTE)
set (CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${ELEMENTS_ROOT}/cmake")

set(ELEMENTS_BUILD_EXAMPLES OFF)
add_subdirectory(${ELEMENTS_ROOT} elements)
include(ElementsConfigCommon)

set(ELEMENTS_APP_PROJECT "Elements Example")
set(ELEMENTS_APP_TITLE "Elements Example")
set(ELEMENTS_APP_COPYRIGHT "Copyright (c) 2020 cansik")
set(ELEMENTS_APP_ID "ch.cansik.example")
set(ELEMENTS_APP_VERSION "1.0")

set(ELEMENTS_APP_RESOURCES)

# COCOA library needed
find_library(COCOA_LIBRARY Cocoa)

add_executable(elements_example main.cpp)
target_link_libraries(elements_example PRIVATE cycfi::elements ${COCOA_LIBRARY})