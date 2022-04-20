cmake_minimum_required(VERSION 3.10)

project(BlockMovement)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/include/)
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/)

set(SRC ${PROJECT_SOURCE_DIR}/main.cpp ${PROJECT_SOURCE_DIR}/PlayerSquare.cpp)
add_executable(BlockMovement ${SRC})
target_include_directories(BlockMovement PUBLIC ${INCLUDE_DIRECTORIES})

target_link_libraries(BlockMovement sfml-graphics sfml-window sfml-audio sfml-system)

