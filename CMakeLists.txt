cmake_minimum_required(VERSION 3.13)

project(sqlite-starter-cpp)

set(CMAKE_CXX_STANDARD 23) # Enable the C++23 standard
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)
add_compile_options(-Wall 
                    -Wextra 
                    -Wpedantic 
                    -Wconversion 
                    -Wdouble-promotion 
                    -Wcast-qual 
                    -Wduplicated-branches 
                    -Wduplicated-cond 
                    -Winit-self 
                    -Wlogical-op 
                    -Wshadow)

add_executable(exe ${SOURCE_FILES})
find_package(fmt CONFIG REQUIRED)
target_link_libraries(exe PRIVATE fmt::fmt)