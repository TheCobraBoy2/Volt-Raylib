cmake_minimum_required(VERSION 3.20)
project(VoltRaylib_Test LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(Dependencies)

# ------------------------------
# Collect library files
# ------------------------------
file(GLOB_RECURSE LIB_HEADERS
    CONFIGURE_DEPENDS
    include/*.h
    include/*.hpp
    include/*.hh
    include/*.inl
)

file(GLOB_RECURSE LIB_SOURCES
    CONFIGURE_DEPENDS
    src/*.c
    src/*.cpp
    src/*.cc
    src/*.cxx
)

# ------------------------------
# Build Volt-Raylib
# ------------------------------
add_library(VoltRaylib STATIC
    ${LIB_HEADERS}
    ${LIB_SOURCES}
)

target_include_directories(VoltRaylib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

target_link_libraries(VoltRaylib
    PUBLIC
        raylib
        -lstdc++exp
)

# ------------------------------
# Collect test/client files
# ------------------------------
file(GLOB_RECURSE TEST_SOURCES
    CONFIGURE_DEPENDS
    test/*.c
    test/*.cpp
    test/*.cc
    test/*.cxx
    test/*.h
    test/*.hpp 
    test/*.hh
    test/*.inl
)

add_executable(VoltRaylib_Test
    ${TEST_SOURCES}
)

target_link_libraries(VoltRaylib_Test
    PRIVATE
        VoltRaylib
        -lstdc++exp
)
