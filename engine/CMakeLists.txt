list(APPEND ENGINE_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/src/core/Engine.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/core/Engine.h
        ${CMAKE_CURRENT_LIST_DIR}/src/device/Device.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/device/Device.h
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/thirdparty/glad)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/thirdparty/glfw)
include(${CMAKE_CURRENT_SOURCE_DIR}/deps/thirdparty/imgui.cmake)

list(APPEND ENGINE_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/deps/thirdparty/glad/include ${CMAKE_CURRENT_SOURCE_DIR}/deps/thirdparty/glfw/include ${CMAKE_CURRENT_SOURCE_DIR}/deps/thirdparty/imgui )
list(APPEND ENGINE_LIBRARIES glad glfw imgui)

add_library("engine" STATIC ${ENGINE_SOURCES})

target_include_directories("engine" PUBLIC ${ENGINE_INCLUDE})
target_link_libraries("engine" PUBLIC ${ENGINE_SOURCES})
