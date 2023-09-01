cmake_minimum_required(VERSION 3.26)
project(GraphicsTesting)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include_directories(deps/glfw/include)
add_subdirectory(deps/glfw glfw)

include_directories(deps/glad/include)
add_subdirectory(deps/glad glad)

include_directories(deps/vulkan-headers/include)

add_executable(GraphicsTesting main.cpp)

target_link_libraries(GraphicsTesting glfw glad)
