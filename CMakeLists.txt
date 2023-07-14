# CMakeLists.txt for Tools Collection
#
# © 2021-2023 by Tanja84DK

cmake_minimum_required(VERSION 3.8)

project(tanja84dk_tools VERSION 0.1.1)

option(tanja84dk_tools_BUILD_TESTING OFF)

option(BUILD_SHARED_LIBS OFF)

set(tanja84dk_tools_HEADERS
	include/Tanja84dk/tools/tools.h
)

set(tanja84dk_tools_SOURCES
	src/tools.cpp
)

include(cmake/tanja84dk_warnings.cmake)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(cmake/CPM.cmake)

add_library(tanja84dk_tools ${tanja84dk_tools_SOURCES})

add_library(Tanja84dk::tools ALIAS tanja84dk_tools)
add_library(Tanja84dk_tools ALIAS tanja84dk_tools)

target_include_directories(tanja84dk_tools
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(tanja84dk_tools
	PRIVATE
		cxx_std_17
)

set_target_properties(tanja84dk_tools
	PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
		CXX_STANDARD 17
		VERSION ${tanja84dk_tools_VERSION}
		SOVERSION ${tanja84dk_tools_VERSION_MAJOR}
)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR OR tanja84dk_tools_BUILD_TESTING STREQUAL ON)
	add_subdirectory(test)
endif()
