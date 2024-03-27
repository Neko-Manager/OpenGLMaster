# CMakeList.txt : CMake project for OpenGLV2024, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("OpenGLV2024")

include_directories(includes)
include_directories(includes/imgui)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/core)

#Add IMGUI headers
set( IMGUI_HEADERS
    includes/imgui/imgui.h
    includes/imgui/imconfig.h
    includes/imgui/imgui_impl_opengl3.h
    includes/imgui/imgui_impl_glfw.h
    includes/imgui/imgui_impl_opengl3_loader.h
)

#Add IMGUI sources
set( IMGUI_SOURCE
    includes/imgui/imgui.cpp
    includes/imgui/imgui_demo.cpp
    includes/imgui/imgui_draw.cpp
    includes/imgui/imgui_widgets.cpp
    includes/imgui/imgui_impl_opengl3.cpp
    includes/imgui/imgui_impl_glfw.cpp
    includes/imgui/imgui_tables.cpp
)

set( HEADER_FILES
   includes/stb_image.h
   OpenGLV2024.h
   core/Application.h 
   core/Window.h 
   core/Scene.h
   core/SceneGraph.h 
   core/Actor.h
   core/Transform.h
   core/Component.h
   core/Tag.h
)

set (SRC_FILES
  OpenGLV2024.cpp
  includes/glad.c
  core/Application.cpp
  core/Window.cpp
  core/Scene.cpp
  core/Actor.cpp
)

# Add source to this project's executable.
add_executable (OpenGLV2024  ${IMGUI_HEADERS} ${IMGUI_SOURCE} ${HEADER_FILES} ${SRC_FILES} 
                OpenGLV2024.cpp OpenGLV2024.h 
                core/Application.h core/Application.cpp
                core/Window.h core/Window.cpp
                core/Scene.h core/Scene.cpp 
                core/SceneGraph.h 
                core/Actor.h core/Actor.cpp
                core/Transform.h 
                core/Component.h  
                core/Tag.h
) 

#target_link_libraries(OpenGLV2024 glfw)
target_link_libraries(OpenGLV2024 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw3.lib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OpenGLV2024 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
