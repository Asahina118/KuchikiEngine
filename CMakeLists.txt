cmake_minimum_required (VERSION 3.8)
project ("KuchikiEngine")

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB IMGUI_SOURCES 
    "src/Imgui/*.cpp"
)

add_executable (${PROJECT_NAME} 
	${SOURCES}
	${IMGUI_SOURCES}
	src/KuchikiEngine.cpp
	extern/glad/src/glad.c
)

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
