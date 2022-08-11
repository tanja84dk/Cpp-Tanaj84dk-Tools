cmake_minimum_required(VERSION 3.8)
project(Tanja84dkTools_tests)

set(Sources
    src/ToolsTests.cpp
)

add_executable(${PROJECT_NAME} ${Sources})
set_target_properties(${This} PROPERTIES
    FOLDER Tests
)

#target_include_directories(${This} PRIVATE ..)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Tanja84dk::Tools
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
