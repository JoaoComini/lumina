cmake_minimum_required(VERSION 3.8)
project(lumina VERSION 0.0.0)

include_directories("./include")

set(
    SOURCE_FILES
    "./src/network/Server.cpp"
    "./src/network/Client.cpp"
    "./src/network/ServerMessageFactory.cpp"
    "./src/engine/Lobby.cpp"
    "./src/engine/Room.cpp"
    "./src/engine/Application.cpp"
)

set(
    HEADER_FILES
    "./include/network/Server.hpp"
    "./include/network/Client.hpp"
    "./include/network/Address.hpp"
    "./include/network/Packet.hpp"
)

add_library(
    lumina STATIC
    "${SOURCE_FILES}"
)

target_compile_options(lumina PRIVATE -Werror)
target_compile_features(lumina PRIVATE cxx_std_11)

add_subdirectory(third_party/enet)
add_subdirectory(third_party/scratchy)

set(TARGET_BUILD_PLATFORM "linux")

set(PHYSX_ROOT_DIR "${CMAKE_SOURCE_DIR}/third_party/PhysX/physx")
set(PXSHARED_PATH "${PHYSX_ROOT_DIR}/../pxshared")
set(PXSHARED_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
set(CMAKEMODULES_PATH "${PHYSX_ROOT_DIR}/../externals/cmakemodules")
set(PX_OUTPUT_LIB_DIR "${CMAKE_CURRENT_BINARY_DIR}/build/PhysX")
set(PX_OUTPUT_BIN_DIR "${CMAKE_CURRENT_BINARY_DIR}/build/PhysX")

add_subdirectory(third_party/PhysX/physx/compiler/public)

add_subdirectory(sandbox)

target_include_directories(
    enet
    PUBLIC
    third_party/enet/include
)

target_link_libraries(lumina PUBLIC enet scratchy PhysX PhysXCharacterKinematic)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)

    add_subdirectory(third_party/googletest/googletest)

    set(
        TEST_SOURCE_FILES
        "test/network/unit/ServerTest.cpp"
    )

    add_executable(
        test_main
        "${TEST_SOURCE_FILES}"
    )

    target_link_libraries(test_main PRIVATE lumina gtest_main)
endif()
