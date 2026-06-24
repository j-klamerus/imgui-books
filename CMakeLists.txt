cmake_minimum_required(VERSION 3.16)
project(MyImGuiApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find GLFW
find_package(glfw3 REQUIRED)

# ImGui sources
set(IMGUI_SOURCES
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/backends/imgui_impl_glfw.cpp
    external/imgui/backends/imgui_impl_opengl3.cpp
)

#project source files
set(SRC_SOURCES
    src/main.cpp
    src/history.cpp
    src/interface.cpp
)

add_executable(MyImGuiApp
    src/main.cpp
    src/history.cpp
    src/interface.cpp
    src/addBook.cpp
    src/log.cpp
    external/imgui/imgui_demo.cpp
    ${IMGUI_SOURCES}
)

target_include_directories(MyImGuiApp PRIVATE
    include
    external/imgui
    external/imgui/backends
    external/json/include
)

target_link_libraries(MyImGuiApp PRIVATE
    glfw
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)

set_target_properties(MyImGuiApp PROPERTIES
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_BUNDLE_NAME "My ImGui App"
    MACOSX_BUNDLE_BUNDLE_VERSION "1.0"
    MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0"
)