#pragma once

#include <string>
#include <vector>
#include <map>
#include <optional>
#include <filesystem>

namespace coreweb {
namespace types {

/**
 * @brief Represents a CoreWeb configuration
 * 
 * This struct contains all the global configuration settings
 * for the CoreWeb framework, including paths, security settings,
 * and default values.
 */
struct ConfigType {
    /// Paths configuration
    struct Paths {
        std::filesystem::path projects_directory;   ///< Directory for projects
        std::filesystem::path plugins_directory;    ///< Directory for plugins
        std::filesystem::path temp_directory;       ///< Directory for temporary files
        std::filesystem::path logs_directory;       ///< Directory for logs
    } paths;

    /// Security configuration
    struct Security {
        bool sandbox_plugins;               ///< Whether to sandbox plugins
        bool automatic_updates;             ///< Whether to enable automatic updates
        int plugin_timeout_ms;              ///< Timeout for plugin execution in milliseconds
        std::vector<std::string> allowed_origins; ///< Allowed origins for network requests
        std::map<std::string, bool> default_permissions; ///< Default permissions for plugins
    } security;

    /// UI configuration
    struct UI {
        std::string theme;                  ///< UI theme
        bool dark_mode;                     ///< Whether to use dark mode
        int font_size;                      ///< Font size
        std::string locale;                 ///< Locale for UI
    } ui;

    /// Network configuration
    struct Network {
        int api_port;                       ///< Port for API server
        bool use_https;                     ///< Whether to use HTTPS
        std::map<std::string, std::string> proxies; ///< Proxy configurations
    } network;

    /// Logging configuration
    struct Logging {
        enum class Level {
            DEBUG,
            INFO,
            WARNING,
            ERROR,
            CRITICAL
        };
        Level level;                        ///< Log level
        bool file_logging;                  ///< Whether to log to file
        bool console_logging;               ///< Whether to log to console
        int max_log_files;                  ///< Maximum number of log files
        int max_log_size_kb;                ///< Maximum log file size in KB
    } logging;

    // Constructor with default values
    ConfigType();

    // Static factory methods
    static ConfigType create_default_config();
    static std::optional<ConfigType> load_from_file(const std::filesystem::path& path);
    
    // Save to file
    bool save_to_file(const std::filesystem::path& path) const;

    // Logging level conversion helper
    static std::string log_level_to_string(Logging::Level level);
    static std::optional<Logging::Level> string_to_log_level(const std::string& str);
};

} // namespace types
} // namespace coreweb 