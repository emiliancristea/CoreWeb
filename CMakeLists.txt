cmake_minimum_required(VERSION 3.20)

project(CoreWeb VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add subdirectories
add_subdirectory(libs)
add_subdirectory(core)
add_subdirectory(cli)

# Enable testing (will be configured further later)
enable_testing()

# Print configuration summary
message(STATUS "Project Name: ${CMAKE_PROJECT_NAME}")
message(STATUS "Project Version: ${PROJECT_VERSION}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}") 