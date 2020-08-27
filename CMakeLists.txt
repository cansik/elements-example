cmake_minimum_required(VERSION 3.16)
project(elements_example LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# elements
set(ELEMENTS_ROOT ${PROJECT_SOURCE_DIR}/elements)
get_filename_component(ELEMENTS_ROOT "${ELEMENTS_ROOT}" ABSOLUTE)
set (CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${ELEMENTS_ROOT}/cmake")

set(ELEMENTS_BUILD_EXAMPLES OFF)

# If we are building outside the project, you need to set ELEMENTS_ROOT:
if (NOT ELEMENTS_BUILD_EXAMPLES)
    include(ElementsConfigCommon)
    set(ELEMENTS_BUILD_EXAMPLES OFF)
    add_subdirectory(${ELEMENTS_ROOT} elements)
endif()

set(ELEMENTS_APP_PROJECT "Elements_Example")
set(ELEMENTS_APP_TITLE "Elements Example")
set(ELEMENTS_APP_COPYRIGHT "Copyright (c) 2020 cansik")
set(ELEMENTS_APP_ID "ch.cansik.example")
set(ELEMENTS_APP_VERSION "1.0")

set(ELEMENTS_APP_RESOURCES)

include(ElementsConfigApp)
