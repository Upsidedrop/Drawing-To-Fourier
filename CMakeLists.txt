cmake_minimum_required(VERSION 3.16)
project(CoTrans)

add_executable(CoTrans src/main.cpp src/math.cpp src/drawneq.cpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

target_include_directories(CoTrans PUBLIC include)

target_link_libraries(CoTrans ${SDL2_LIBRARIES})
