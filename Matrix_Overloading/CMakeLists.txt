cmake_minimum_required(VERSION 3.8)
project(Matrix)

set(CMAKE_CXX_STANDARD 14)
set(GPP_ENABLE_WARNINGS "-O0 -Wall -Werror -Wno-unused-result")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GPP_ENABLE_WARNINGS}")


add_executable(Matrix main.cpp RowElementItr.cpp RowElementItr.h RowItr.cpp RowItr.h ColItr.h ColElementItr.cpp ColElementItr.h ColItr.cpp Matrix.cpp Matrix.h MatrixError.cpp MatrixError.h MatrixInnerDimensionMismatchError.cpp MatrixInnerDimensionMismatchError.h MatrixSizeError.cpp MatrixSizeError.h MatrixSizeMismatchError.cpp MatrixSizeMismatchError.h)