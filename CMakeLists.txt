cmake_minimum_required(VERSION 3.17)
project(side VERSION 1.0 LANGUAGES CXX)
add_executable(side)
target_sources(side PRIVATE
    "main.cpp"
)
add_subdirectory(imgui)
target_link_libraries(side PRIVATE glfw)