# CoreWeb Framework

A C++-based framework for building lightweight, secure, and cross-platform desktop applications using web technologies.

## Overview

CoreWeb integrates a C++20 backend with system webviews and a React/TypeScript frontend, offering a robust plugin system, a command-line interface (CLI), and example applications. It aims to surpass Tauri and Electron in performance, security, and developer experience.

## Key Components

- **Core Backend**: Manages logic, project management, plugins, and configurations using C++20
- **Control Center Client**: A React/TypeScript/Tailwind CSS interface rendered via C++-managed webview
- **CLI Tool**: coreweb-cli for scaffolding, building, and running projects
- **Plugin System**: Extensible via C++ modules and WebAssembly (WASM) with secure APIs
- **Example Apps**: Demonstrations of capabilities (productivity, utility, creative apps)

## Goals

- Minimal resource usage (~3–5 MB binaries, ~15–25 MB memory, 200–400 ms startup)
- Security through sandboxing, modern C++ practices, and static analysis
- Cross-platform compatibility (Windows, macOS, Linux)
- Seamless developer experience with CLI, hot-reloading, TypeScript support, and comprehensive documentation

## Project Structure

- `/core` - Core C++ backend components
- `/cli` - Command-line interface tool
- `/libs` - Shared libraries and utilities
- `/client` - Control Center Client (React/TypeScript frontend)
- `/examples` - Example applications
- `/infra` - Infrastructure and CI/CD configuration
- `/docs` - Documentation

## Getting Started

*Coming soon*

## Requirements

- C++20 compatible compiler (GCC 10+, Clang 10+, MSVC 2019+)
- CMake 3.15 or higher
- Node.js 18.x or higher (for frontend development)
- Platform-specific webview dependencies:
  - Windows: WebView2
  - macOS: WKWebView
  - Linux: WebKitGTK

## License

*TBD* 