cmake_minimum_required (VERSION 3.8)
project ("KuchikiEngine")

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

find_package(OpenGL REQUIRED)

add_executable (KuchikiEngine 
	"src/KuchikiEngine.cpp"
	extern/glad/src/glad.c
 "src/Window/Window.h" "src/Window/Window.cpp" "src/Scene/Scene.h" "src/Camera/Camera.h" "src/Camera/Camera.cpp" "src/Scene/Scene.cpp" "src/Inputs/InputHandler.h" "src/Inputs/GUI.h" "src/Shaders/Shader.h" "src/Entities/Mesh.h" "src/Entities/Shape.h" )

add_subdirectory(extern/glfw)

target_link_libraries(${PROJECT_NAME} PRIVATE
	glfw
	OpenGL::GL
)

target_include_directories(${PROJECT_NAME} PRIVATE
	extern/glad/include
	extern
	src/
)

set_property(TARGET KuchikiEngine PROPERTY CXX_STANDARD 20)
