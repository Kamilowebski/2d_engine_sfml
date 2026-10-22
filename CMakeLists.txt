
cmake_minimum_required(VERSION 3.28)

project(PRO LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(MAKE_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

configure_file(
        "${CMAKE_SOURCE_DIR}/assets/arial.ttf"
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/arial.ttf"
        COPYONLY
)


include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.1.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)

FetchContent_MakeAvailable(SFML)

add_executable(PRO
        src/main.cpp
        src/Engine.cpp
        src/Engine.hpp
)

target_link_libraries(PRO
        PRIVATE
        SFML::Graphics
)

target_compile_features(PRO PRIVATE cxx_std_17)
