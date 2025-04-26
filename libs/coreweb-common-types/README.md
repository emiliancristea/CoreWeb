# CoreWeb Common Types Library

This library defines the fundamental data types used throughout the CoreWeb framework. It provides C++ structs for projects, plugins, and configurations, along with JSON serialization/deserialization capabilities.

## Components

- **ProjectType**: Defines the structure of a CoreWeb project, including metadata, frontend/backend configuration, build settings, and window properties.
- **PluginType**: Represents a plugin with metadata, type information, build details, permissions, and API endpoints.
- **ConfigType**: Contains global framework configuration including paths, security settings, UI preferences, network settings, and logging options.
- **Serialization**: Provides functions to convert the above types to/from JSON for storage and transmission.

## Dependencies

- **nlohmann/json**: For JSON handling (serialization/deserialization)
- **C++20**: For std::filesystem and other modern C++ features

## Usage

```cpp
#include "coreweb-common-types/project_type.h"
#include "coreweb-common-types/serialization.h"

// Create a new project
auto project = coreweb::types::ProjectType::create_default_project("my-app");

// Customize project settings
project.window.width = 1024;
project.window.height = 768;
project.metadata.description = "My awesome CoreWeb application";

// Save to file
project.save_to_file("my-app.json");

// Later, load from file
auto loaded_project = coreweb::types::ProjectType::load_from_file("my-app.json");
``` 