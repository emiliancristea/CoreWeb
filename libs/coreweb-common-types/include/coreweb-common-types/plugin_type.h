#pragma once

#include <string>
#include <vector>
#include <map>
#include <optional>
#include <filesystem>

namespace coreweb {
namespace types {

/**
 * @brief Represents a CoreWeb plugin configuration
 * 
 * This struct contains all the information required to define
 * a CoreWeb plugin, including its metadata, dependencies,
 * permissions, and API endpoints.
 */
struct PluginType {
    /// Plugin metadata
    struct Metadata {
        std::string name;               ///< Plugin name
        std::string version;            ///< Plugin version (semver)
        std::string description;        ///< Plugin description
        std::string author;             ///< Plugin author
        std::vector<std::string> license; ///< Plugin license(s)
        std::map<std::string, std::string> repository; ///< Repository information
    } metadata;

    /// Plugin type information
    enum class Type {
        CPP_MODULE,                     ///< C++ native module
        WASM,                           ///< WebAssembly module
        NATIVE_BINARY                   ///< Native binary executable
    };
    Type type;

    /// Plugin build information
    struct Build {
        std::string source_path;        ///< Path to source code
        std::vector<std::string> dependencies; ///< Dependencies required
        std::map<std::string, std::string> options; ///< Build options
    } build;

    /// Plugin permissions
    struct Permissions {
        bool filesystem_read;           ///< Read from filesystem
        bool filesystem_write;          ///< Write to filesystem
        bool network;                   ///< Access network
        bool camera;                    ///< Access camera
        bool microphone;                ///< Access microphone
        bool notifications;             ///< Send notifications
        bool clipboard;                 ///< Access clipboard
        std::vector<std::string> custom_permissions; ///< Custom permissions
    } permissions;

    /// API endpoints provided by the plugin
    struct API {
        std::vector<std::string> functions; ///< Exposed function names
        std::map<std::string, std::string> events; ///< Events that can be emitted
    } api;

    // Constructor with default values
    PluginType();

    // Static factory methods
    static PluginType create_default_plugin(const std::string& name, Type type);
    static std::optional<PluginType> load_from_file(const std::filesystem::path& path);
    
    // Save to file
    bool save_to_file(const std::filesystem::path& path) const;

    // Type conversion helper
    static std::string type_to_string(Type type);
    static std::optional<Type> string_to_type(const std::string& str);
};

} // namespace types
} // namespace coreweb 