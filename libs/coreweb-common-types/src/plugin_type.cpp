#include "coreweb-common-types/plugin_type.h"
#include "coreweb-common-types/serialization.h"
#include <fstream>

namespace coreweb {
namespace types {

PluginType::PluginType() {
    // Initialize with default values
    metadata.name = "unnamed-plugin";
    metadata.version = "0.1.0";
    metadata.description = "A CoreWeb plugin";
    metadata.author = "";
    
    type = Type::CPP_MODULE;
    
    // Default permissions (all disabled)
    permissions.filesystem_read = false;
    permissions.filesystem_write = false;
    permissions.network = false;
    permissions.camera = false;
    permissions.microphone = false;
    permissions.notifications = false;
    permissions.clipboard = false;
}

PluginType PluginType::create_default_plugin(const std::string& name, Type type) {
    PluginType plugin;
    plugin.metadata.name = name;
    plugin.type = type;
    
    // Set up reasonable defaults based on plugin type
    switch (type) {
        case Type::CPP_MODULE:
            plugin.build.source_path = "src/plugin.cpp";
            break;
        case Type::WASM:
            plugin.build.source_path = "src/plugin.rs"; // Assuming Rust for WASM
            break;
        case Type::NATIVE_BINARY:
            plugin.build.source_path = "src/main.cpp";
            break;
    }
    
    return plugin;
}

std::optional<PluginType> PluginType::load_from_file(const std::filesystem::path& path) {
    try {
        std::ifstream file(path);
        if (!file.is_open()) {
            return std::nullopt;
        }
        
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        return Serialization::from_json_string_to_plugin(content);
    } catch (...) {
        return std::nullopt;
    }
}

bool PluginType::save_to_file(const std::filesystem::path& path) const {
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

std::string PluginType::type_to_string(Type type) {
    switch (type) {
        case Type::CPP_MODULE:
            return "cpp_module";
        case Type::WASM:
            return "wasm";
        case Type::NATIVE_BINARY:
            return "native_binary";
        default:
            return "unknown";
    }
}

std::optional<PluginType::Type> PluginType::string_to_type(const std::string& str) {
    if (str == "cpp_module") {
        return Type::CPP_MODULE;
    } else if (str == "wasm") {
        return Type::WASM;
    } else if (str == "native_binary") {
        return Type::NATIVE_BINARY;
    } else {
        return std::nullopt;
    }
}

} // namespace types
} // namespace coreweb 