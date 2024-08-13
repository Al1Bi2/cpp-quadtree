cmake_minimum_required(VERSION 3.16)
include(FetchContent)

project(quadtree)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BINARY main_tst)

FetchContent_Declare(
spdlog
GIT_REPOSITORY https://github.com/gabime/spdlog.git
GIT_TAG v1.12.0)
FetchContent_MakeAvailable(spdlog)


include_directories(ntree)
add_subdirectory(ntree)

add_executable(${BINARY} main.cpp  "ntree/nvector.cpp")
target_link_libraries(${BINARY} PUBLIC MyLib)