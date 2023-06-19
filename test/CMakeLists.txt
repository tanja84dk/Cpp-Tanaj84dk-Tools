cmake_minimum_required(VERSION 3.8)

project(Tanja84dk_tools_tests)

set(Tanja84dk_tools_tests_SOURCES
  src/tanja84dk_tools_test.cpp
)

add_executable(Tanja84dk_tools_tests ${Tanja84dk_tools_tests_SOURCES})

set_target_properties(${Tanja84dk_tools_tests}
  PROPERTIES
    FOLDER Tests
)


target_link_libraries(Tanja84dk_tools_tests PRIVATE
    Tanja84dk::tools
)

add_test(Tanja84dk_tools_tests Tanja84dk_tools_tests)
