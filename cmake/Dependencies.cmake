include(FetchContent)

find_package(raylib 5.5 QUIET)

if (raylib_FOUND)
  message(STATUS "Using system raylib")
  return()
endif()

message(STATUS "System raylib not found, fetching...")

FetchContent_Declare(
  raylib 
  GIT_REPOSITORY https://github.com/raysan5/raylib.git 
  GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)