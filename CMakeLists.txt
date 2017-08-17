cmake_minimum_required(VERSION 3.8)
project(CodeSnippet)
set(CMAKE_CXX_STANDARD 14)

# 编译google test，会在当前目录生成libtest.a动态库
add_subdirectory(./googletest)

include_directories(
        ./src/string
        ./src/sort
        ./src/system
        ./googletest/googletest/include/gtest
)

link_directories(./googletest)
set(LIBRARIES gtest pthread)

aux_source_directory(./src/string SRC_STRING)
aux_source_directory(./src/sort SRC_SORT)
aux_source_directory(./src/system SRC_SYSTEM)

set(SOURCE_FILES main.cpp ${SRC_STRING} ${SRC_SORT} ${SRC_SYSTEM})

add_executable(CodeSnippet ${SOURCE_FILES})
target_link_libraries(CodeSnippet ${LIBRARIES})