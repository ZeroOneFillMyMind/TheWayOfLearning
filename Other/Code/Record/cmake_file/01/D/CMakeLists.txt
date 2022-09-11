cmake_minimum_required(VERSION 3.5)

project(hello_shared)

add_library(hello_shared SHARED
    src/hello.cpp
    )

target_include_directories(hello_shared PUBLIC ${PROJECT_SOURCE_DIR}/include/shared)


add_executable(hello_bin src/main.cpp)

target_link_libraries(hello_bin PRIVATE hello_shared)
