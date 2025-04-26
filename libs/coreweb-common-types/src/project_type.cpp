#include "coreweb-common-types/project_type.h"
#include "coreweb-common-types/serialization.h"
#include <fstream>

namespace coreweb {
namespace types {

ProjectType::ProjectType() {
    // Initialize with default values
    metadata.name = "unnamed-project";
    metadata.version = "0.1.0";
    metadata.description = "A CoreWeb project";
    metadata.author = "";
    
    frontend.framework = "react";
    frontend.entry_point = "src/index.tsx";
    
    build.target = "desktop";
    
    window.title = "CoreWeb App";
    window.width = 800;
    window.height = 600;
    window.resizable = true;
    window.decorated = true;
    window.transparent = false;
    window.always_on_top = false;
}

ProjectType ProjectType::create_default_project(const std::string& name) {
    ProjectType project;
    project.metadata.name = name;
    project.window.title = name;
    
    // Set up default frontend dependencies
    project.frontend.dependencies["react"] = "^18.2.0";
    project.frontend.dependencies["react-dom"] = "^18.2.0";
    project.frontend.dev_dependencies["typescript"] = "^5.0.0";
    project.frontend.dev_dependencies["tailwindcss"] = "^3.3.0";
    
    return project;
}

std::optional<ProjectType> ProjectType::load_from_file(const std::filesystem::path& path) {
    try {
        std::ifstream file(path);
        if (!file.is_open()) {
            return std::nullopt;
        }
        
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        return Serialization::from_json_string_to_project(content);
    } catch (...) {
        return std::nullopt;
    }
}

bool ProjectType::save_to_file(const std::filesystem::path& path) const {
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

} // namespace types
} // namespace coreweb 