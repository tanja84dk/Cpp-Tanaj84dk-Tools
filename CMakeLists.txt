# CMakeLists.txt for Tools Collection
#
# © 2021 by Tanja84DK

# CMakeLists.txt for Tools Collection
#
# © 2021-2022 by Tanja84DK

cmake_minimum_required(VERSION 3.8)

project(Tanja84dkTools VERSION 0.1.1)

set(Headers
    include/Tanja84dk/Tools/Tools.h
)

set(Sources
    src/Tools.cpp
)

add_library(${PROJECT_NAME}
	${Sources}
)

add_library(libs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} ${Shared_Libraries} ${Static_Libraries})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(${PROJECT_NAME}
	PRIVATE
		cxx_std_14
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
	VERSION ${PROJECT_VERSION}
	SOVERSION ${PROJECT_VERSION_MAJOR}
)

if(BUILD_TESTING)
	add_subdirectory(tests)
endif()