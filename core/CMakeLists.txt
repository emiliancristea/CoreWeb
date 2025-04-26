set(CORE_SOURCE_FILES
    src/main.cpp
    src/core_app.cpp
    src/storage/sqlite_manager.cpp
    src/api/http_server.cpp
    src/plugin/plugin_manager.cpp
    src/config/config_manager.cpp
)

set(CORE_HEADER_FILES
    include/core_app.h
    include/storage/sqlite_manager.h
    include/api/http_server.h
    include/plugin/plugin_manager.h
    include/config/config_manager.h
)

# Create a library with the core functionality
add_library(coreweb_core STATIC
    ${CORE_SOURCE_FILES}
    ${CORE_HEADER_FILES}
)

# Set include directories for the library
target_include_directories(coreweb_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set the output name for the library
set_target_properties(coreweb_core PROPERTIES
    OUTPUT_NAME coreweb_core
)

# Create the main CoreWeb executable
add_executable(coreweb src/main.cpp)

# Link the executable with the core library
target_link_libraries(coreweb PRIVATE coreweb_core)

# Find and link dependencies (to be expanded as needed)
# TODO: Add find_package calls for required dependencies like SQLite, nlohmann_json, etc.

# Install rules
install(TARGETS coreweb_core
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(TARGETS coreweb
    RUNTIME DESTINATION bin
)

install(FILES ${CORE_HEADER_FILES}
    DESTINATION include/coreweb
) 