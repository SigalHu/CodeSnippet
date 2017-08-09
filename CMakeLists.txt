cmake_minimum_required(VERSION 3.8)
project(CodeSnippet)
set(CMAKE_CXX_STANDARD 14)

# 编译google test，会在当前目录生成libtest.a动态库
add_subdirectory(./googletest)

include_directories(
        ./src/string
        ./googletest/googletest/include/gtest
)

link_directories(./googletest)
set(LIBRARIES gtest pthread)

aux_source_directory(
        ./src/string
        DIR_SRCS
)

set(SOURCE_FILES main.cpp ${DIR_SRCS})

add_executable(CodeSnippet ${SOURCE_FILES})
target_link_libraries(CodeSnippet ${LIBRARIES})