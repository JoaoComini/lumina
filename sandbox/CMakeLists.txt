cmake_minimum_required(VERSION 3.8)
project(lumina-sandbox VERSION 0.0.0)

include_directories("./include")

add_executable(
    server
    "./server.cpp"
)

add_executable(
    client
    "./client.cpp"
)

target_compile_features(server PRIVATE cxx_std_11)
target_compile_features(client PRIVATE cxx_std_11)

target_link_libraries(server PUBLIC lumina)

target_link_libraries(client PUBLIC enet)
