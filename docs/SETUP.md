# CoreWeb Setup Guide

This guide provides instructions for setting up the development environment for the CoreWeb framework.

## Prerequisites

Ensure you have the following dependencies installed:

*   **Git:** For version control. ([Download Git](https://git-scm.com/downloads))
*   **CMake:** Version 3.20 or higher. ([Download CMake](https://cmake.org/download/))
*   **C++ Compiler:** A compiler supporting C++20.
    *   **Windows:** Visual Studio 2019 or later (with C++ workload).
    *   **macOS:** Xcode Command Line Tools (Clang).
    *   **Linux:** GCC 10+ or Clang 11+.
*   **vcpkg:** For C++ dependency management. ([vcpkg GitHub](https://github.com/microsoft/vcpkg#getting-started))
    *   Follow the vcpkg setup instructions for your platform.
    *   Ensure vcpkg is integrated into your build environment (e.g., using `vcpkg integrate install`).

## Getting the Source Code

1.  Clone the repository:
    ```bash
    git clone https://github.com/emiliancristea/CoreWeb.git
    cd CoreWeb
    ```

## Building the Project (Initial Setup)

*(Detailed build instructions will be added as the project progresses. This section currently outlines the expected process.)*

1.  **Install Dependencies:** vcpkg should automatically handle dependencies listed in `vcpkg.json` (to be added later) when configuring CMake.
2.  **Configure CMake:**
    ```bash
    # Create a build directory
    mkdir build
    cd build

    # Configure the project (adjust generator and toolchain path as needed)
    cmake .. -DCMAKE_TOOLCHAIN_FILE=[path-to-vcpkg]/scripts/buildsystems/vcpkg.cmake
    ```
3.  **Build:**
    ```bash
    cmake --build .
    ```

## Platform-Specific Notes

*(Details about webview runtime installation and other platform requirements will be added here.)*

*   **Windows:** Requires the WebView2 Runtime. ([Download WebView2 Runtime](https://developer.microsoft.com/en-us/microsoft-edge/webview2/#download-section))
*   **macOS:** Requires macOS 11 (Big Sur) or later for WKWebView features.
*   **Linux:** Requires WebKitGTK development libraries (e.g., `libwebkit2gtk-4.0-dev` on Debian/Ubuntu). 