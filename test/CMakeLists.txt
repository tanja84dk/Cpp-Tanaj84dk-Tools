cmake_minimum_required(VERSION 3.8)
set(This ToolsTests)

set(Sources
    src/ToolsTests.cpp
)

add_executable(${This} ${Sources})
set_target_properties(${This} PROPERTIES
    FOLDER Tests
)

target_include_directories(${This} PRIVATE ..)

target_link_libraries(${This} PUBLIC
    Tools
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
