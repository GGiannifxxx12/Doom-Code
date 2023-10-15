cmake_minimum_required(VERSION 3.10)
project(doom_engine)
set(CMAKE_CXX_STANDARD 14)
add_executable(doom_engine main.cpp)
target_link_libraries(doom_engine
    SDL2
    OpenGL
    GLEW
)