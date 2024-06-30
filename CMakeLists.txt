cmake_minimum_required(VERSION 3.0.0)

project(ray_traicing VERSION 0.1.0)

set(SOURCE_EXE main.cpp)

include_directories(RayTracing)

add_executable(ray_traicing ${SOURCE_EXE})

target_link_libraries(ray_traicing)