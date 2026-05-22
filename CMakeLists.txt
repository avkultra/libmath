cmake_minimum_required(VERSION 3.10)

project(libmath)

add_library(math INTERFACE)

target_include_directories(math INTERFACE include)

install(DIRECTORY include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)
