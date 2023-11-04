cmake_minimum_required(VERSION 3.27)

project(Conductor
        VERSION 0.1
		DESCRIPTION "Program for folder looking"
		HOMEPAGE_URL "https://github.com/Hixac/ABIBAS.git"
		LANGUAGES CXX)

set(SOURCE
  src/main.cpp src/Base.h src/LoggingSystem.h
  src/window/window.h src/window/window.cpp)

set(IMGUI_DIR ext/imgui/)
set(SPDLOG_DIR ext/spdlog/)

set(IMGUI_SRC
  /home/hixac/Projects/Conductor/ext/imgui/misc
  /home/hixac/Projects/Conductor/ext/imgui/imstb_truetype.h
  /home/hixac/Projects/Conductor/ext/imgui/imstb_textedit.h
  /home/hixac/Projects/Conductor/ext/imgui/imstb_rectpack.h
  /home/hixac/Projects/Conductor/ext/imgui/imgui_widgets.cpp
  /home/hixac/Projects/Conductor/ext/imgui/imgui_tables.cpp
  /home/hixac/Projects/Conductor/ext/imgui/imgui_internal.h
  /home/hixac/Projects/Conductor/ext/imgui/imgui_impl_opengl3_loader.h
  /home/hixac/Projects/Conductor/ext/imgui/imgui_impl_opengl3.h
  /home/hixac/Projects/Conductor/ext/imgui/imgui_impl_opengl3.cpp
  /home/hixac/Projects/Conductor/ext/imgui/imgui_impl_glfw.h
  /home/hixac/Projects/Conductor/ext/imgui/imgui_impl_glfw.cpp
  /home/hixac/Projects/Conductor/ext/imgui/imgui_draw.cpp
  /home/hixac/Projects/Conductor/ext/imgui/imgui_demo.cpp
  /home/hixac/Projects/Conductor/ext/imgui/imgui.h
  /home/hixac/Projects/Conductor/ext/imgui/imgui.cpp
  /home/hixac/Projects/Conductor/ext/imgui/imconfig.h)

set(SPDLOG_SRC
  /home/hixac/Projects/Conductor/ext/spdlog/spdlog)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -g)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  
add_executable(${PROJECT_NAME} ${SOURCE} ${IMGUI_SRC} ${SPDLOG_SRC})

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw)

target_include_directories(${PROJECT_NAME} PRIVATE ${SPDLOG_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${IMGUI_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE src/)
target_include_directories(${PROJECT_NAME} PRIVATE src/window/)
