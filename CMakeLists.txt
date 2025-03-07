cmake_minimum_required(VERSION 3.20)
project(Paddy-Farm)

set(CMAKE_CXX_STANDARD 20)
find_package(OpenGL REQUIRED)

include_directories(include)

add_executable(${PROJECT_NAME}
src/main.cpp
src/glad.c
src/shaderProgram.cpp
)   

target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)
