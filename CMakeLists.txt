cmake_minimum_required(VERSION 3.15)
project(boiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(OpenGL REQUIRED)

add_subdirectory(libs/glfw)
add_subdirectory(libs/glad)
add_subdirectory(libs/glm)
add_subdirectory(libs/assimp)

add_executable(boiler src/main.cpp src/ShaderProgram.h src/ShaderProgram.cpp libs/stb/stb_image.h src/TextureLoader.h src/WindowManager.h src/Maths.h src/Renderer.h)

target_compile_definitions(boiler PUBLIC GLFW_INCLUDE_NONE )

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT "boiler")
target_link_libraries(boiler assimp glm glad glfw ${OPENGL_gl_LIBRARY})
