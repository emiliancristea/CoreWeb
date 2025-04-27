cmake_minimum_required(VERSION 3.20)

project(CoreWeb VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Find Packages via vcpkg ---
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(unofficial-sqlite3 CONFIG REQUIRED)
find_package(c-ares CONFIG REQUIRED) # Dependency for cpp-httplib with SSL
find_package(OpenSSL REQUIRED)      # Dependency for cpp-httplib with SSL & libcurl
find_package(ZLIB REQUIRED)         # Dependency for cpp-httplib & libcurl
find_package(cpp-httplib CONFIG REQUIRED)
find_package(CURL REQUIRED)
find_package(GTest CONFIG REQUIRED)

# --- Add Subdirectories ---
add_subdirectory(libs)
add_subdirectory(core)
add_subdirectory(cli)

# --- Enable Testing ---
enable_testing()
# Add tests using gtest_discover_tests later

# --- Temporary Verification Target --- (REMOVE LATER)
add_executable(verification_target main_temp.cpp)
target_include_directories(verification_target PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(verification_target PRIVATE nlohmann_json::nlohmann_json GTest::gtest GTest::gmock)

# --- Print configuration summary ---
message(STATUS "Project Name: ${CMAKE_PROJECT_NAME}")
message(STATUS "Project Version: ${PROJECT_VERSION}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Found nlohmann_json: ${nlohmann_json_FOUND}")
message(STATUS "Found cpp-httplib: ${cpp-httplib_FOUND}")
message(STATUS "Found SQLite3: ${unofficial-sqlite3_FOUND}")
message(STATUS "Found CURL: ${CURL_FOUND}")
message(STATUS "Found GTest: ${GTest_FOUND}") 