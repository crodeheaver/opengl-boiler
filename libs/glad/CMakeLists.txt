cmake_minimum_required(VERSION 3.15)

project(glad LANGUAGES C)

add_library(glad STATIC src/glad.c include/glad/glad.h include/KHR/khrplatform.h)

target_include_directories(glad PUBLIC include)

