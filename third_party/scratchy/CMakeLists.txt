cmake_minimum_required(VERSION 3.0.0)
project(scratchy VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include)

set(
    SOURCE_FILES
    ./src/BitWriter.cpp ./src/BitReader.cpp
)

add_library(
    scratchy STATIC
    ${SOURCE_FILES}
)

target_include_directories(
    scratchy 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)
