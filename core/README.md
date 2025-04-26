# CoreWeb Core

The core component of the CoreWeb framework, responsible for handling the backend functionality including:

- Project and plugin management
- Database storage (SQLite)
- HTTP/REST API for client communication
- Plugin system execution and sandboxing
- Configuration management

## Architecture

The core is built with modern C++20 and is designed with the following principles:

- Modularity: Components are separated into logical modules
- Security: Sandboxed plugin execution and secure API boundaries
- Performance: Minimal resource usage and fast startup times
- Cross-platform: Works on Windows, macOS, and Linux

## Components

- **CoreApp**: Main application class that orchestrates all components
- **SQLiteManager**: Handles database operations for persistent storage
- **HttpServer**: Provides REST API endpoints for client communication
- **PluginManager**: Loads and executes plugins securely
- **ConfigManager**: Manages global and project-specific configurations

## Build Requirements

- C++20 compatible compiler
- CMake 3.15+
- Dependencies:
  - SQLite3
  - nlohmann/json
  - cpp-httplib
  - libcurl
  - Wasmer (for WASM plugin support)

## Development

The core components are organized in a modular fashion to facilitate testing and extension:

```
core/
├── include/              # Public headers
│   ├── core_app.h
│   ├── storage/
│   ├── api/
│   ├── plugin/
│   └── config/
├── src/                  # Implementation files
│   ├── core_app.cpp
│   ├── main.cpp
│   ├── storage/
│   ├── api/
│   ├── plugin/
│   └── config/
└── tests/                # Unit and integration tests
``` 