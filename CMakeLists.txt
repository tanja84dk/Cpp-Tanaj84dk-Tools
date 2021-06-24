# CMakeLists.txt for Tools Collection
#
# © 2021 by Tanja84DK

cmake_minimum_required(VERSION 3.8)

set(This Tools)

set(Headers
    include/Tools/Tools.h
)

set(Sources
    src/Tools.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
set_target_properties(${This} PROPERTIES
    FOLDER Libraries
)

target_include_directories(${This} PUBLIC include)
