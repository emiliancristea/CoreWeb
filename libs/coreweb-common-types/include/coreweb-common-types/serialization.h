#pragma once

#include "project_type.h"
#include "plugin_type.h"
#include "config_type.h"
#include <string>
#include <nlohmann/json.hpp>

namespace coreweb {
namespace types {

/**
 * @brief JSON serialization and deserialization for CoreWeb types
 * 
 * This class provides functions to convert CoreWeb types to JSON and back.
 * It uses the nlohmann/json library for JSON handling.
 */
class Serialization {
public:
    // ProjectType serialization/deserialization
    static nlohmann::json to_json(const ProjectType& project);
    static ProjectType from_json_to_project(const nlohmann::json& json);
    static std::string to_json_string(const ProjectType& project);
    static ProjectType from_json_string_to_project(const std::string& json_str);
    
    // PluginType serialization/deserialization
    static nlohmann::json to_json(const PluginType& plugin);
    static PluginType from_json_to_plugin(const nlohmann::json& json);
    static std::string to_json_string(const PluginType& plugin);
    static PluginType from_json_string_to_plugin(const std::string& json_str);
    
    // ConfigType serialization/deserialization
    static nlohmann::json to_json(const ConfigType& config);
    static ConfigType from_json_to_config(const nlohmann::json& json);
    static std::string to_json_string(const ConfigType& config);
    static ConfigType from_json_string_to_config(const std::string& json_str);
};

} // namespace types
} // namespace coreweb 