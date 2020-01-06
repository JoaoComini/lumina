cmake_minimum_required(VERSION 3.8)
project(lumina VERSION 0.1.0)

include_directories("./include")

set(
    SOURCE_FILES
    "./src/Address.cpp"
    "./src/Server.cpp"
)

set(
    HEADER_FILES
    "./src/Address.hpp"
    "./src/Server.hpp"
)

add_library(
    lumina STATIC
    "${SOURCE_FILES}"
)

target_compile_options(lumina PRIVATE -Werror)
target_compile_features(lumina PRIVATE cxx_std_11)

add_subdirectory(third_party/enet)
add_subdirectory(third_party/scratchy)

target_include_directories(
    enet 
    PUBLIC 
    third_party/enet/include
)

target_link_libraries(lumina PRIVATE enet scratchy)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)

    add_subdirectory(third_party/googletest/googletest)

    set(
        TEST_SOURCE_FILES
    )

    add_executable(
        test_main
        "${TEST_SOURCE_FILES}"
    )

    target_link_libraries(test_main PRIVATE lumina gtest_main)
endif()
