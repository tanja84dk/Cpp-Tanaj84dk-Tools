find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
add_executable(tanja84dk_tools_test src/tanja84dk_tools_test.cpp)
target_link_libraries(tanja84dk_tools_test PRIVATE Catch2::Catch2WithMain Tanja84dk::tools)

include(CTest)

# These tests need their own main
#add_executable(custom-main-tests test.cpp test-main.cpp)