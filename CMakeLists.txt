cmake_minimum_required(VERSION 3.5)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)")
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(SFML_OpenGL_test VERSION 1.0.1)

message("  -- CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
message("  -- PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
message("  -- PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")
message("  -- CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")
message("  -- CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")

include_directories("${PROJECT_BINARY_DIR}")

# Define source and executable
set(EXECUTABLE_NAME "opengl-sfml")

set(SOURCES
		src/main.cpp)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

# Look for other CMake scripts
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Find any version 2.X of SFML library
find_package(SFML 2 REQUIRED network audio graphics window system)
message("  -- SFML_FOUND = ${SFML_FOUND}, ${SFML_INCLUDE_DIR}")
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${SMFL_INCLUDE_DIR})

# Find package OpenGL
find_package(OpenGL REQUIRED)
message("  -- OPENGL_FOUND = ${OPENGL_FOUND}, ${OPENGL_INCLUDE_DIR}")
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${OPENGL_INCLUDE_DIR})

# Linking founded libraries
target_link_libraries(
		${EXECUTABLE_NAME}
		PRIVATE
		${SFML_LIBRARIES} ${SFML_DEPENDENCIES}
		${OPENGL_LIBRARIES})

# Setup properties
set_target_properties(${EXECUTABLE_NAME} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON)
