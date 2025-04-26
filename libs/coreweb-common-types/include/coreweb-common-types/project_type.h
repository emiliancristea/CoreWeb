#pragma once

#include <string>
#include <vector>
#include <map>
#include <optional>
#include <filesystem>

namespace coreweb {
namespace types {

/**
 * @brief Represents a CoreWeb project configuration
 * 
 * This struct contains all the information required to define
 * a CoreWeb project, including its metadata, dependencies,
 * build configuration, and plugin settings.
 */
struct ProjectType {
    /// Project metadata
    struct Metadata {
        std::string name;               ///< Project name
        std::string version;            ///< Project version (semver)
        std::string description;        ///< Project description
        std::string author;             ///< Project author
        std::vector<std::string> license; ///< Project license(s)
        std::map<std::string, std::string> repository; ///< Repository information
    } metadata;

    /// Frontend configuration
    struct Frontend {
        std::string framework;          ///< Frontend framework (e.g., "react", "svelte")
        std::string entry_point;        ///< Entry point path
        std::map<std::string, std::string> dependencies; ///< Frontend dependencies
        std::map<std::string, std::string> dev_dependencies; ///< Frontend dev dependencies
        std::map<std::string, std::string> settings; ///< Frontend settings
    } frontend;

    /// Backend configuration
    struct Backend {
        std::vector<std::string> plugins; ///< Enabled plugins
        std::map<std::string, std::string> dependencies; ///< Backend dependencies
        std::map<std::string, std::map<std::string, std::string>> plugin_config; ///< Plugin configurations
    } backend;

    /// Build configuration
    struct Build {
        std::string target;             ///< Build target platform
        std::map<std::string, std::string> options; ///< Build options
    } build;

    /// Application window configuration
    struct Window {
        std::string title;              ///< Window title
        int width;                      ///< Window width
        int height;                     ///< Window height
        bool resizable;                 ///< Whether window is resizable
        bool decorated;                 ///< Whether window has decorations
        bool transparent;               ///< Whether window is transparent
        bool always_on_top;             ///< Whether window is always on top
    } window;

    // Constructor with default values
    ProjectType();

    // Getters/setters omitted for brevity

    // Static factory methods
    static ProjectType create_default_project(const std::string& name);
    static std::optional<ProjectType> load_from_file(const std::filesystem::path& path);
    
    // Save to file
    bool save_to_file(const std::filesystem::path& path) const;
};

} // namespace types
} // namespace coreweb 