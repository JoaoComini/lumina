cmake_minimum_required(VERSION 3.0.0)
project(lumina VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include)

set(
    SOURCE_FILES
    ./src/Address.cpp ./src/Server.cpp
)

add_library(
    lumina STATIC
    ${SOURCE_FILES}
)

add_subdirectory(third_party/enet)
add_subdirectory(third_party/scratchy)

target_include_directories(
    enet 
    PUBLIC 
    third_party/enet/include
)

target_link_libraries(lumina PUBLIC enet scratchy)
