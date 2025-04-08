# VERSIONING
cmake_minimum_required(VERSION 3.10)

# PROJECT INIT
project(CryoMesh)

# COMPILER VER
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# VARS
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(FMT_TEST OFF CACHE BOOL "" FORCE)
set(FMT_DOC OFF CACHE BOOL "" FORCE)
set(FMT_INSTALL OFF CACHE BOOL "" FORCE)

# EXTERNAL INCLUDES
add_subdirectory(External/glfw)
add_subdirectory(External/fmt)

# PATHS
include_directories(External/glfw/include)
include_directories(External/fmt/include)
include_directories(Engine/)

# FILES
file(GLOB_RECURSE ENGINE_SOURCE Engine/*)

# OPTIONS SETTING
if (MSVC)
    add_compile_options(/utf-8)
endif()

# BUILD
add_executable(Engine ${ENGINE_SOURCE})

# LINKING
target_link_libraries(Engine glfw fmt::fmt)