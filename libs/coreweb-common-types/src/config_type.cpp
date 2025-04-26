#include "coreweb-common-types/config_type.h"
#include "coreweb-common-types/serialization.h"
#include <fstream>

namespace coreweb {
namespace types {

ConfigType::ConfigType() {
    // Initialize with default values for paths
    paths.projects_directory = std::filesystem::current_path() / "projects";
    paths.plugins_directory = std::filesystem::current_path() / "plugins";
    paths.temp_directory = std::filesystem::temp_directory_path() / "coreweb";
    paths.logs_directory = std::filesystem::current_path() / "logs";
    
    // Initialize security settings
    security.sandbox_plugins = true;
    security.automatic_updates = true;
    security.plugin_timeout_ms = 5000; // 5 seconds
    security.allowed_origins = {"localhost"};
    
    // Default permission settings
    security.default_permissions["filesystem_read"] = false;
    security.default_permissions["filesystem_write"] = false;
    security.default_permissions["network"] = false;
    security.default_permissions["camera"] = false;
    security.default_permissions["microphone"] = false;
    security.default_permissions["notifications"] = false;
    security.default_permissions["clipboard"] = false;
    
    // UI settings
    ui.theme = "light";
    ui.dark_mode = false;
    ui.font_size = 14;
    ui.locale = "en-US";
    
    // Network settings
    network.api_port = 8080;
    network.use_https = false;
    
    // Logging settings
    logging.level = Logging::Level::INFO;
    logging.file_logging = true;
    logging.console_logging = true;
    logging.max_log_files = 5;
    logging.max_log_size_kb = 1024; // 1MB
}

ConfigType ConfigType::create_default_config() {
    return ConfigType();
}

std::optional<ConfigType> ConfigType::load_from_file(const std::filesystem::path& path) {
    try {
        std::ifstream file(path);
        if (!file.is_open()) {
            return std::nullopt;
        }
        
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        return Serialization::from_json_string_to_config(content);
    } catch (...) {
        return std::nullopt;
    }
}

bool ConfigType::save_to_file(const std::filesystem::path& path) const {
    try {
        std::ofstream file(path);
        if (!file.is_open()) {
            return false;
        }
        
        file << Serialization::to_json_string(*this);
        return true;
    } catch (...) {
        return false;
    }
}

std::string ConfigType::log_level_to_string(Logging::Level level) {
    switch (level) {
        case Logging::Level::DEBUG:
            return "debug";
        case Logging::Level::INFO:
            return "info";
        case Logging::Level::WARNING:
            return "warning";
        case Logging::Level::ERROR:
            return "error";
        case Logging::Level::CRITICAL:
            return "critical";
        default:
            return "unknown";
    }
}

std::optional<ConfigType::Logging::Level> ConfigType::string_to_log_level(const std::string& str) {
    if (str == "debug") {
        return Logging::Level::DEBUG;
    } else if (str == "info") {
        return Logging::Level::INFO;
    } else if (str == "warning") {
        return Logging::Level::WARNING;
    } else if (str == "error") {
        return Logging::Level::ERROR;
    } else if (str == "critical") {
        return Logging::Level::CRITICAL;
    } else {
        return std::nullopt;
    }
}

} // namespace types
} // namespace coreweb 