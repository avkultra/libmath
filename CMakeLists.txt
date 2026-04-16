cmake_minimum_required(VERSION 3.10)

project(libmath)

add_library(math STATIC
    src/libmath.cpp
)

target_include_directories(math
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)


install(TARGETS math
    ARCHIVE DESTINATION /usr/local/lib
)

install(FILES include/libmath.h
    DESTINATION /usr/local/include
)
