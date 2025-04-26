set(CLI_SOURCE_FILES
    src/main.cpp
    src/cli_app.cpp
    src/commands/create_command.cpp
    src/commands/run_command.cpp
    src/commands/build_command.cpp
)

set(CLI_HEADER_FILES
    include/cli_app.h
    include/commands/command.h
    include/commands/create_command.h
    include/commands/run_command.h
    include/commands/build_command.h
)

# Create a library with the CLI functionality
add_library(coreweb_cli_lib STATIC
    ${CLI_SOURCE_FILES}
    ${CLI_HEADER_FILES}
)

# Set include directories for the library
target_include_directories(coreweb_cli_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link with dependencies (including coreweb_core)
target_link_libraries(coreweb_cli_lib PRIVATE
    coreweb_core
)

# Create the CLI executable
add_executable(coreweb_cli src/main.cpp)

# Set the output name for the executable
set_target_properties(coreweb_cli PROPERTIES
    OUTPUT_NAME coreweb-cli
)

# Link the executable with the CLI library
target_link_libraries(coreweb_cli PRIVATE coreweb_cli_lib)

# Install rules
install(TARGETS coreweb_cli_lib
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(TARGETS coreweb_cli
    RUNTIME DESTINATION bin
)

install(FILES ${CLI_HEADER_FILES}
    DESTINATION include/coreweb-cli
) 