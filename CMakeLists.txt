cmake_minimum_required(VERSION 3.26)
project(GraphicsTesting)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Find QT lol
if (WIN32)
    set(QT_BASEDIR "C:/Qt/6.5.2/msvc2019_64")
    set(CMAKE_PREFIX_PATH ${QT_BASEDIR})
endif ()

set(PROJECT_SOURCES
        src/main.cpp
        src/LauncherWindow.cpp
        src/LauncherWindow.h

)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(deps/glfw/include)
add_subdirectory(deps/glfw glfw)

include_directories(deps/glad/include)
add_subdirectory(deps/glad glad)

include_directories(deps/vulkan-headers/include)

if (WIN32)
    add_executable(GraphicsTesting WIN32 ${PROJECT_SOURCES})
    target_link_options(GraphicsTesting PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/ENTRY:mainCRTStartup>)
    configure_file("${QT_BASEDIR}/bin/Qt6Core.dll" "${CMAKE_BINARY_DIR}/Qt6Core.dll" COPYONLY)
    configure_file("${QT_BASEDIR}/bin/Qt6Gui.dll" "${CMAKE_BINARY_DIR}/Qt6Gui.dll" COPYONLY)
    configure_file("${QT_BASEDIR}/bin/Qt6Widgets.dll" "${CMAKE_BINARY_DIR}/Qt6Widgets.dll" COPYONLY)
    configure_file("${QT_BASEDIR}/plugins/platforms/qwindows.dll" "${CMAKE_BINARY_DIR}/platforms/qwindows.dll" COPYONLY)
    configure_file("${QT_BASEDIR}/plugins/platforms/qminimal.dll" "${CMAKE_BINARY_DIR}/platforms/qminimal.dll" COPYONLY)
    configure_file("${QT_BASEDIR}/plugins/imageformats/qjpeg.dll" "${CMAKE_BINARY_DIR}/imageformats/qjpeg.dll" COPYONLY)
    configure_file("${QT_BASEDIR}/plugins/tls/qschannelbackend.dll" "${CMAKE_BINARY_DIR}/tls/qschannelbackend.dll" COPYONLY)
else ()
    add_executable(GraphicsTesting ${PROJECT_SOURCES})
endif ()

target_link_libraries(GraphicsTesting glfw glad Qt6::Widgets)
