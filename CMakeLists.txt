cmake_minimum_required(VERSION 3.8)
project(CodeSnippet)

include_directories(
        include
)

aux_source_directory(
        source
        DIR_SRCS
)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp ${DIR_SRCS})

add_executable(CodeSnippet ${SOURCE_FILES})