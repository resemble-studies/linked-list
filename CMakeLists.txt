# License: MIT. See LICENSE in root directory.
# Date: 2020/06/29

cmake_minimum_required(VERSION 3.1.0)

project("ensemble-linked-list" LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("${CMAKE_CURRENT_LIST_DIR}/inc")

set(ENSEMBLE_LINKED_LIST_LIB "ensemble-linked-list-lib")
add_library(${ENSEMBLE_LINKED_LIST_LIB} STATIC "")
target_sources(
    ${ENSEMBLE_LINKED_LIST_LIB}
    PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/src/ensemble/linked-list.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/inc/ensemble/linked-list.hpp"
)

if (CMAKE_BUILD_TYPE MATCHES "^[Dd]ebug")
    set(ENSEMBLE_LINKED_LIST_EXE "ensemble-linked-list-exe")
    add_executable(
        ${ENSEMBLE_LINKED_LIST_EXE}
        "${CMAKE_CURRENT_LIST_DIR}/test/main.cpp")
    target_link_libraries(
        ${ENSEMBLE_LINKED_LIST_EXE}
        ${ENSEMBLE_LINKED_LIST_LIB})
endif ()
