# CoreWeb CLI

The command-line interface (CLI) tool for the CoreWeb framework, providing developers with commands to create, build, and run CoreWeb applications.

## Features

- Project scaffolding with templates
- Building projects for different platforms
- Running projects with hot-reloading
- Managing plugins
- Project configuration
- Packaging for distribution

## Commands

- `create`: Create a new CoreWeb project with a chosen template
- `run`: Run a CoreWeb project with hot-reloading for development
- `build`: Build a CoreWeb project for distribution
- `plugin install`: Install a plugin for use in projects
- `plugin remove`: Remove a plugin from the system
- `config`: View and set configuration options

## Usage

```bash
# Create a new project
coreweb-cli create my-app --template react-ts

# Run a project with hot-reloading
coreweb-cli run --project-path ./my-app

# Build a project for distribution
coreweb-cli build --project-path ./my-app --target windows

# Install a plugin
coreweb-cli plugin install file-system --version 1.0.0

# Remove a plugin
coreweb-cli plugin remove file-system
```

## Architecture

The CLI is built with C++20 and follows a command pattern architecture:

```
cli/
├── include/                # Public headers
│   ├── cli_app.h           # Main CLI application class
│   └── commands/           # Command classes
│       ├── command.h       # Base command interface
│       ├── create_command.h
│       ├── run_command.h
│       └── build_command.h
├── src/                    # Implementation files
│   ├── cli_app.cpp         # Main CLI application
│   ├── main.cpp            # Entry point
│   └── commands/           # Command implementations
│       ├── create_command.cpp
│       ├── run_command.cpp
│       └── build_command.cpp
└── tests/                  # Unit and integration tests
```

## Build Requirements

- C++20 compatible compiler
- CMake 3.15+
- Dependencies:
  - CoreWeb Core library
  - nlohmann/json
  - CLI11 (for command-line parsing) 