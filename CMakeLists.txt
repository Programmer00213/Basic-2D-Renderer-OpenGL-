cmake_minimum_required(VERSION 3.10)
project(Review)

# creating a variable named PROJECT_FILES
file(GLOB BUFFER_FILES src/buffers/*.cpp)
set(
    PROJECT_FILES
    src/glad.c
    src/main.cpp
    src/init.cpp
    src/shader/shader.cpp
    src/texture/texture.cpp
    src/renderer/renderer.cpp
    ${BUFFER_FILES}
)

# specific include and lib directories
include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

# compile source code
add_executable(main ${PROJECT_FILES})

# link libraries to the obj code
target_link_libraries(main glfw3dll)