cmake_minimum_required(VERSION 3.8)
project(CodeSnippet)
set(CMAKE_CXX_STANDARD 14)

# 编译google test，会在当前目录生成libtest.a动态库
add_subdirectory(./googletest)

include_directories(
        ./src/string
        ./src/sort
        ./googletest/googletest/include/gtest
)

link_directories(./googletest)
set(LIBRARIES gtest pthread)

aux_source_directory(./src/string SRC_STRING)
aux_source_directory(./src/sort SRC_SORT)

set(SOURCE_FILES main.cpp ${SRC_STRING} ${SRC_SORT})

add_executable(CodeSnippet ${SOURCE_FILES})
target_link_libraries(CodeSnippet ${LIBRARIES})