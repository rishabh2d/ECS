cmake_minimum_required(VERSION 3.8)
project(untitled3)

set(CMAKE_C_STANDARD 11)
set(GCC_ENABLE_WARNINGS "-O1 -Wall -Werror -Wno-unused-result")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_ENABLE_WARNINGS}")

set(SOURCE_FILES main.c create_canvas.c create_canvas.h horizontal.c horizontal.h diagonal.c diagonal.h add.c add.h delete.c delete.h resize.c resize.h saveLoad.c saveLoad.h delete_struct.h)
add_executable(untitled3 ${SOURCE_FILES})