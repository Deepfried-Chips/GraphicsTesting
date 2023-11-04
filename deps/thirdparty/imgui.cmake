cmake_minimum_required(VERSION 3.26)

project(imgui)

list(APPEND IMGUI_HEADERS
        ${CMAKE_CURRENT_LIST_DIR}/imgui/imconfig.h
        ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui.h
        ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_internal.h
        ${CMAKE_CURRENT_LIST_DIR}/imgui/imstb_rectpack.h
        ${CMAKE_CURRENT_LIST_DIR}/imgui/imstb_textedit.h
        ${CMAKE_CURRENT_LIST_DIR}/imgui/imstb_truetype.h
        ${CMAKE_CURRENT_LIST_DIR}/imgui/backends/imgui_impl_opengl3.h
        ${CMAKE_CURRENT_LIST_DIR}/imgui/backends/imgui_impl_vulkan.h
        ${CMAKE_CURRENT_LIST_DIR}/imgui/backends/imgui_impl_glfw.h
)

list(APPEND IMGUI_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui.cpp
        ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_demo.cpp
        ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_draw.cpp
        ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_tables.cpp
        ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_widgets.cpp
        ${CMAKE_CURRENT_LIST_DIR}/imgui/backends/imgui_impl_opengl3.cpp
        ${CMAKE_CURRENT_LIST_DIR}/imgui/backends/imgui_impl_vulkan.cpp
        ${CMAKE_CURRENT_LIST_DIR}/imgui/backends/imgui_impl_glfw.cpp

)

list(APPEND IMGUI_SOURCES ${IMGUI_HEADERS})
add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PRIVATE ${CMAKE_CURRENT_LIST_DIR}/imgui)
