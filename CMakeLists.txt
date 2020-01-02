cmake_minimum_required(VERSION 3.9)
project(MathAlgorithms)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MathAlgorithms)

file(GLOB SOURCE_FILES
    "src/*.h"
    "src/*.cpp"
)

add_executable(MathAlgorithms ${SOURCE_FILES} )
