# CMakeLists.txt for Tools Collection
#
# © 2021-2023 by Tanja84DK

cmake_minimum_required(VERSION 3.8)

project(Tanja84dk_tools VERSION 0.1.1)

set(BUILD_TESTING ON)

set(Tanja84dk_tools_HEADERS
  include/Tanja84dk/tools/tools.h
)

set(Tanja84dk_tools_SOURCES
  src/tools.cpp
)

add_library(Tanja84dk_tools ${Tanja84dk_tools_SOURCES} ${Tanja84dk_tools_HEADERS})

add_library(Tanja84dk::tools ALIAS Tanja84dk_tools)

target_include_directories(Tanja84dk_tools
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(Tanja84dk_tools
	PRIVATE
		cxx_std_17
)

set_target_properties(Tanja84dk_tools
  PROPERTIES
	  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
		CXX_STANDARD 17
		VERSION ${PROJECT_VERSION}
		SOVERSION ${PROJECT_VERSION_MAJOR}
)

if(BUILD_TESTING)
	add_subdirectory(test)
endif()