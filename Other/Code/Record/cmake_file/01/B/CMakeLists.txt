cmake_minimum_required(VERSION 3.5)

project(hello_header)

file(GLOB SOURCES "src/*.cpp")
# 使用"" 引用路径
# 另一种表示方法
# set(SOURCES
#     src/hello.cpp
#     src/main.cpp
# )

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

