cmake_minimum_required(VERSION 3.15)
project(CoreWeb VERSION 0.1.0 LANGUAGES CXX)

# Set C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories for the project
include_directories(${CMAKE_SOURCE_DIR})

# Add subdirectories for different components
add_subdirectory(core)
add_subdirectory(cli)
add_subdirectory(libs)

# Enable testing
enable_testing()

# Add options for build configuration
option(COREWEB_BUILD_TESTS "Build the CoreWeb test suite" ON)
option(COREWEB_BUILD_EXAMPLES "Build the CoreWeb example applications" OFF)

# Add subdirectory for tests if enabled
if(COREWEB_BUILD_TESTS)
    add_subdirectory(tests)
endif()

# Add subdirectory for examples if enabled
if(COREWEB_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Output configuration information
message(STATUS "CoreWeb configuration:")
message(STATUS "  C++ Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "  Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "  Build tests: ${COREWEB_BUILD_TESTS}")
message(STATUS "  Build examples: ${COREWEB_BUILD_EXAMPLES}") 