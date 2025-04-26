set(COMMON_TYPES_SOURCE_FILES
    src/project_type.cpp
    src/plugin_type.cpp
    src/config_type.cpp
)

set(COMMON_TYPES_HEADER_FILES
    include/coreweb-common-types/project_type.h
    include/coreweb-common-types/plugin_type.h
    include/coreweb-common-types/config_type.h
    include/coreweb-common-types/serialization.h
)

# Create the library
add_library(coreweb_common_types STATIC
    ${COMMON_TYPES_SOURCE_FILES}
    ${COMMON_TYPES_HEADER_FILES}
)

# Set include directories
target_include_directories(coreweb_common_types PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set the output name
set_target_properties(coreweb_common_types PROPERTIES
    OUTPUT_NAME coreweb_common_types
)

# TODO: Find and link with nlohmann_json for JSON serialization

# Install rules
install(TARGETS coreweb_common_types
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(FILES ${COMMON_TYPES_HEADER_FILES}
    DESTINATION include
) 