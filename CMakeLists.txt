cmake_minimum_required(VERSION 3.20)
project(Carbonara_DRV8874 CXX C)

set(CMAKE_CXX_STANDARD 17)

# Include the source directory so local headers are recognized
include_directories(src)

# Define the library target containing your source files
add_library(Carbonara_DRV8874
        src/Carbonara_DRV8874.cpp
        src/Carbonara_DRV8874.h
)