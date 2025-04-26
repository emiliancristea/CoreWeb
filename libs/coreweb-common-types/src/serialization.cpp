#include "coreweb-common-types/serialization.h"
#include <iostream>
#include <stdexcept>

namespace coreweb {
namespace types {

// ProjectType serialization
nlohmann::json Serialization::to_json(const ProjectType& project) {
    nlohmann::json j;
    
    // Metadata
    j["metadata"]["name"] = project.metadata.name;
    j["metadata"]["version"] = project.metadata.version;
    j["metadata"]["description"] = project.metadata.description;
    j["metadata"]["author"] = project.metadata.author;
    j["metadata"]["license"] = project.metadata.license;
    j["metadata"]["repository"] = project.metadata.repository;
    
    // Frontend
    j["frontend"]["framework"] = project.frontend.framework;
    j["frontend"]["entry_point"] = project.frontend.entry_point;
    j["frontend"]["dependencies"] = project.frontend.dependencies;
    j["frontend"]["dev_dependencies"] = project.frontend.dev_dependencies;
    j["frontend"]["settings"] = project.frontend.settings;
    
    // Backend
    j["backend"]["plugins"] = project.backend.plugins;
    j["backend"]["dependencies"] = project.backend.dependencies;
    j["backend"]["plugin_config"] = project.backend.plugin_config;
    
    // Build
    j["build"]["target"] = project.build.target;
    j["build"]["options"] = project.build.options;
    
    // Window
    j["window"]["title"] = project.window.title;
    j["window"]["width"] = project.window.width;
    j["window"]["height"] = project.window.height;
    j["window"]["resizable"] = project.window.resizable;
    j["window"]["decorated"] = project.window.decorated;
    j["window"]["transparent"] = project.window.transparent;
    j["window"]["always_on_top"] = project.window.always_on_top;
    
    return j;
}

ProjectType Serialization::from_json_to_project(const nlohmann::json& j) {
    ProjectType project;
    
    try {
        // Metadata
        if (j.contains("metadata")) {
            const auto& metadata = j["metadata"];
            if (metadata.contains("name")) project.metadata.name = metadata["name"].get<std::string>();
            if (metadata.contains("version")) project.metadata.version = metadata["version"].get<std::string>();
            if (metadata.contains("description")) project.metadata.description = metadata["description"].get<std::string>();
            if (metadata.contains("author")) project.metadata.author = metadata["author"].get<std::string>();
            if (metadata.contains("license")) project.metadata.license = metadata["license"].get<std::vector<std::string>>();
            if (metadata.contains("repository")) project.metadata.repository = metadata["repository"].get<std::map<std::string, std::string>>();
        }
        
        // Frontend
        if (j.contains("frontend")) {
            const auto& frontend = j["frontend"];
            if (frontend.contains("framework")) project.frontend.framework = frontend["framework"].get<std::string>();
            if (frontend.contains("entry_point")) project.frontend.entry_point = frontend["entry_point"].get<std::string>();
            if (frontend.contains("dependencies")) project.frontend.dependencies = frontend["dependencies"].get<std::map<std::string, std::string>>();
            if (frontend.contains("dev_dependencies")) project.frontend.dev_dependencies = frontend["dev_dependencies"].get<std::map<std::string, std::string>>();
            if (frontend.contains("settings")) project.frontend.settings = frontend["settings"].get<std::map<std::string, std::string>>();
        }
        
        // Backend
        if (j.contains("backend")) {
            const auto& backend = j["backend"];
            if (backend.contains("plugins")) project.backend.plugins = backend["plugins"].get<std::vector<std::string>>();
            if (backend.contains("dependencies")) project.backend.dependencies = backend["dependencies"].get<std::map<std::string, std::string>>();
            if (backend.contains("plugin_config")) project.backend.plugin_config = backend["plugin_config"].get<std::map<std::string, std::map<std::string, std::string>>>();
        }
        
        // Build
        if (j.contains("build")) {
            const auto& build = j["build"];
            if (build.contains("target")) project.build.target = build["target"].get<std::string>();
            if (build.contains("options")) project.build.options = build["options"].get<std::map<std::string, std::string>>();
        }
        
        // Window
        if (j.contains("window")) {
            const auto& window = j["window"];
            if (window.contains("title")) project.window.title = window["title"].get<std::string>();
            if (window.contains("width")) project.window.width = window["width"].get<int>();
            if (window.contains("height")) project.window.height = window["height"].get<int>();
            if (window.contains("resizable")) project.window.resizable = window["resizable"].get<bool>();
            if (window.contains("decorated")) project.window.decorated = window["decorated"].get<bool>();
            if (window.contains("transparent")) project.window.transparent = window["transparent"].get<bool>();
            if (window.contains("always_on_top")) project.window.always_on_top = window["always_on_top"].get<bool>();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error parsing project JSON: " << e.what() << std::endl;
    }
    
    return project;
}

std::string Serialization::to_json_string(const ProjectType& project) {
    return to_json(project).dump(4); // Pretty print with 4-space indent
}

ProjectType Serialization::from_json_string_to_project(const std::string& json_str) {
    try {
        nlohmann::json j = nlohmann::json::parse(json_str);
        return from_json_to_project(j);
    } catch (const std::exception& e) {
        std::cerr << "Error parsing project JSON string: " << e.what() << std::endl;
        return ProjectType();
    }
}

// PluginType serialization
nlohmann::json Serialization::to_json(const PluginType& plugin) {
    nlohmann::json j;
    
    // Metadata
    j["metadata"]["name"] = plugin.metadata.name;
    j["metadata"]["version"] = plugin.metadata.version;
    j["metadata"]["description"] = plugin.metadata.description;
    j["metadata"]["author"] = plugin.metadata.author;
    j["metadata"]["license"] = plugin.metadata.license;
    j["metadata"]["repository"] = plugin.metadata.repository;
    
    // Type
    j["type"] = PluginType::type_to_string(plugin.type);
    
    // Build
    j["build"]["source_path"] = plugin.build.source_path;
    j["build"]["dependencies"] = plugin.build.dependencies;
    j["build"]["options"] = plugin.build.options;
    
    // Permissions
    j["permissions"]["filesystem_read"] = plugin.permissions.filesystem_read;
    j["permissions"]["filesystem_write"] = plugin.permissions.filesystem_write;
    j["permissions"]["network"] = plugin.permissions.network;
    j["permissions"]["camera"] = plugin.permissions.camera;
    j["permissions"]["microphone"] = plugin.permissions.microphone;
    j["permissions"]["notifications"] = plugin.permissions.notifications;
    j["permissions"]["clipboard"] = plugin.permissions.clipboard;
    j["permissions"]["custom_permissions"] = plugin.permissions.custom_permissions;
    
    // API
    j["api"]["functions"] = plugin.api.functions;
    j["api"]["events"] = plugin.api.events;
    
    return j;
}

PluginType Serialization::from_json_to_plugin(const nlohmann::json& j) {
    PluginType plugin;
    
    try {
        // Metadata
        if (j.contains("metadata")) {
            const auto& metadata = j["metadata"];
            if (metadata.contains("name")) plugin.metadata.name = metadata["name"].get<std::string>();
            if (metadata.contains("version")) plugin.metadata.version = metadata["version"].get<std::string>();
            if (metadata.contains("description")) plugin.metadata.description = metadata["description"].get<std::string>();
            if (metadata.contains("author")) plugin.metadata.author = metadata["author"].get<std::string>();
            if (metadata.contains("license")) plugin.metadata.license = metadata["license"].get<std::vector<std::string>>();
            if (metadata.contains("repository")) plugin.metadata.repository = metadata["repository"].get<std::map<std::string, std::string>>();
        }
        
        // Type
        if (j.contains("type")) {
            std::string type_str = j["type"].get<std::string>();
            auto type = PluginType::string_to_type(type_str);
            if (type) {
                plugin.type = *type;
            }
        }
        
        // Build
        if (j.contains("build")) {
            const auto& build = j["build"];
            if (build.contains("source_path")) plugin.build.source_path = build["source_path"].get<std::string>();
            if (build.contains("dependencies")) plugin.build.dependencies = build["dependencies"].get<std::vector<std::string>>();
            if (build.contains("options")) plugin.build.options = build["options"].get<std::map<std::string, std::string>>();
        }
        
        // Permissions
        if (j.contains("permissions")) {
            const auto& permissions = j["permissions"];
            if (permissions.contains("filesystem_read")) plugin.permissions.filesystem_read = permissions["filesystem_read"].get<bool>();
            if (permissions.contains("filesystem_write")) plugin.permissions.filesystem_write = permissions["filesystem_write"].get<bool>();
            if (permissions.contains("network")) plugin.permissions.network = permissions["network"].get<bool>();
            if (permissions.contains("camera")) plugin.permissions.camera = permissions["camera"].get<bool>();
            if (permissions.contains("microphone")) plugin.permissions.microphone = permissions["microphone"].get<bool>();
            if (permissions.contains("notifications")) plugin.permissions.notifications = permissions["notifications"].get<bool>();
            if (permissions.contains("clipboard")) plugin.permissions.clipboard = permissions["clipboard"].get<bool>();
            if (permissions.contains("custom_permissions")) plugin.permissions.custom_permissions = permissions["custom_permissions"].get<std::vector<std::string>>();
        }
        
        // API
        if (j.contains("api")) {
            const auto& api = j["api"];
            if (api.contains("functions")) plugin.api.functions = api["functions"].get<std::vector<std::string>>();
            if (api.contains("events")) plugin.api.events = api["events"].get<std::map<std::string, std::string>>();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error parsing plugin JSON: " << e.what() << std::endl;
    }
    
    return plugin;
}

std::string Serialization::to_json_string(const PluginType& plugin) {
    return to_json(plugin).dump(4); // Pretty print with 4-space indent
}

PluginType Serialization::from_json_string_to_plugin(const std::string& json_str) {
    try {
        nlohmann::json j = nlohmann::json::parse(json_str);
        return from_json_to_plugin(j);
    } catch (const std::exception& e) {
        std::cerr << "Error parsing plugin JSON string: " << e.what() << std::endl;
        return PluginType();
    }
}

// ConfigType serialization
nlohmann::json Serialization::to_json(const ConfigType& config) {
    nlohmann::json j;
    
    // Paths
    j["paths"]["projects_directory"] = config.paths.projects_directory.string();
    j["paths"]["plugins_directory"] = config.paths.plugins_directory.string();
    j["paths"]["temp_directory"] = config.paths.temp_directory.string();
    j["paths"]["logs_directory"] = config.paths.logs_directory.string();
    
    // Security
    j["security"]["sandbox_plugins"] = config.security.sandbox_plugins;
    j["security"]["automatic_updates"] = config.security.automatic_updates;
    j["security"]["plugin_timeout_ms"] = config.security.plugin_timeout_ms;
    j["security"]["allowed_origins"] = config.security.allowed_origins;
    j["security"]["default_permissions"] = config.security.default_permissions;
    
    // UI
    j["ui"]["theme"] = config.ui.theme;
    j["ui"]["dark_mode"] = config.ui.dark_mode;
    j["ui"]["font_size"] = config.ui.font_size;
    j["ui"]["locale"] = config.ui.locale;
    
    // Network
    j["network"]["api_port"] = config.network.api_port;
    j["network"]["use_https"] = config.network.use_https;
    j["network"]["proxies"] = config.network.proxies;
    
    // Logging
    j["logging"]["level"] = ConfigType::log_level_to_string(config.logging.level);
    j["logging"]["file_logging"] = config.logging.file_logging;
    j["logging"]["console_logging"] = config.logging.console_logging;
    j["logging"]["max_log_files"] = config.logging.max_log_files;
    j["logging"]["max_log_size_kb"] = config.logging.max_log_size_kb;
    
    return j;
}

ConfigType Serialization::from_json_to_config(const nlohmann::json& j) {
    ConfigType config;
    
    try {
        // Paths
        if (j.contains("paths")) {
            const auto& paths = j["paths"];
            if (paths.contains("projects_directory")) config.paths.projects_directory = paths["projects_directory"].get<std::string>();
            if (paths.contains("plugins_directory")) config.paths.plugins_directory = paths["plugins_directory"].get<std::string>();
            if (paths.contains("temp_directory")) config.paths.temp_directory = paths["temp_directory"].get<std::string>();
            if (paths.contains("logs_directory")) config.paths.logs_directory = paths["logs_directory"].get<std::string>();
        }
        
        // Security
        if (j.contains("security")) {
            const auto& security = j["security"];
            if (security.contains("sandbox_plugins")) config.security.sandbox_plugins = security["sandbox_plugins"].get<bool>();
            if (security.contains("automatic_updates")) config.security.automatic_updates = security["automatic_updates"].get<bool>();
            if (security.contains("plugin_timeout_ms")) config.security.plugin_timeout_ms = security["plugin_timeout_ms"].get<int>();
            if (security.contains("allowed_origins")) config.security.allowed_origins = security["allowed_origins"].get<std::vector<std::string>>();
            if (security.contains("default_permissions")) config.security.default_permissions = security["default_permissions"].get<std::map<std::string, bool>>();
        }
        
        // UI
        if (j.contains("ui")) {
            const auto& ui = j["ui"];
            if (ui.contains("theme")) config.ui.theme = ui["theme"].get<std::string>();
            if (ui.contains("dark_mode")) config.ui.dark_mode = ui["dark_mode"].get<bool>();
            if (ui.contains("font_size")) config.ui.font_size = ui["font_size"].get<int>();
            if (ui.contains("locale")) config.ui.locale = ui["locale"].get<std::string>();
        }
        
        // Network
        if (j.contains("network")) {
            const auto& network = j["network"];
            if (network.contains("api_port")) config.network.api_port = network["api_port"].get<int>();
            if (network.contains("use_https")) config.network.use_https = network["use_https"].get<bool>();
            if (network.contains("proxies")) config.network.proxies = network["proxies"].get<std::map<std::string, std::string>>();
        }
        
        // Logging
        if (j.contains("logging")) {
            const auto& logging = j["logging"];
            if (logging.contains("level")) {
                std::string level_str = logging["level"].get<std::string>();
                auto level = ConfigType::string_to_log_level(level_str);
                if (level) {
                    config.logging.level = *level;
                }
            }
            if (logging.contains("file_logging")) config.logging.file_logging = logging["file_logging"].get<bool>();
            if (logging.contains("console_logging")) config.logging.console_logging = logging["console_logging"].get<bool>();
            if (logging.contains("max_log_files")) config.logging.max_log_files = logging["max_log_files"].get<int>();
            if (logging.contains("max_log_size_kb")) config.logging.max_log_size_kb = logging["max_log_size_kb"].get<int>();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error parsing config JSON: " << e.what() << std::endl;
    }
    
    return config;
}

std::string Serialization::to_json_string(const ConfigType& config) {
    return to_json(config).dump(4); // Pretty print with 4-space indent
}

ConfigType Serialization::from_json_string_to_config(const std::string& json_str) {
    try {
        nlohmann::json j = nlohmann::json::parse(json_str);
        return from_json_to_config(j);
    } catch (const std::exception& e) {
        std::cerr << "Error parsing config JSON string: " << e.what() << std::endl;
        return ConfigType();
    }
}

} // namespace types
} // namespace coreweb 