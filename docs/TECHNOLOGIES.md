# CoreWeb Technology Stack

This document outlines the key technologies, libraries, and tools used in the CoreWeb framework.

## Core Dependencies (Managed via vcpkg)

The C++ backend relies on the following libraries, managed using [vcpkg](https://github.com/microsoft/vcpkg) in manifest mode (`vcpkg.json`):

*   **[webview](https://github.com/webview/webview):** Cross-platform webview library (using system webviews: WebView2, WKWebView, WebKitGTK). *(Integration planned)*
*   **[nlohmann/json](https://github.com/nlohmann/json):** JSON library for C++. Used for IPC, configuration, and serialization.
*   **[cpp-httplib](https://github.com/yhirose/cpp-httplib):** Simple C++ HTTP/HTTPS server and client library. Used for internal IPC fallback and potentially the development server.
*   **[SQLite3](https://www.sqlite.org/index.html):** Embedded SQL database engine. Used for storing project, plugin, and configuration data.
*   **[libcurl](https://curl.se/libcurl/):** Client-side URL transfer library. Used for networking tasks (e.g., plugin registry access).
*   **[Wasmer](https://wasmer.io/):** WebAssembly runtime. Used for running WASM plugins, with Ahead-of-Time (AoT) compilation support. *(Integration planned)*
*   **Rust FFI Libraries:** *(Optional)* Bindings for Rust components for enhanced security. Requires `cbindgen` for header generation. *(Integration planned)*

## Testing Frameworks

*   **C++ Unit/Integration Testing:**
    *   **[GoogleTest](https://github.com/google/googletest):** C++ testing framework.
    *   **[RapidCheck](https://github.com/emil-e/rapidcheck):** Property-based testing framework for C++. *(Integration planned)*
*   **Frontend Unit/Integration Testing:**
    *   **[Jest](https://jestjs.io/):** JavaScript testing framework.
*   **End-to-End (E2E) Testing:**
    *   **[Puppeteer](https://pptr.dev/) / [Playwright](https://playwright.dev/):** Browser automation libraries for testing webview content. *(Integration planned)*
*   **Memory Safety:**
    *   **AddressSanitizer (ASan) / UndefinedBehaviorSanitizer (UBSan):** Compiler-based sanitizers. *(CI Integration planned)*
*   **Binary Size Analysis:**
    *   **[Bloaty McBloatface](https://github.com/google/bloaty):** Binary size profiler. *(CI Integration planned)*

## Build System and Tooling

*   **Build System:** [CMake](https://cmake.org/) (Version 3.20+)
*   **Dependency Management:** [vcpkg](https://github.com/microsoft/vcpkg)
*   **Profiling:** [Tracy Profiler](https://github.com/wolfpld/tracy) *(Integration planned)*
*   **Static Analysis:** [Clang-Tidy](https://clang.llvm.org/extra/clang-tidy/) *(CI Integration planned)*
*   **IDE Integration:** Visual Studio Code Extension *(Development planned)*
*   **WebAssembly Debugging:** DWARF support via Wasmer *(Integration planned)*

## Frontend

*   **Framework Agnostic:** Supports any framework/library rendering to HTML/CSS/JS (React, Vue, Svelte examples provided).
*   **Bundling/Minification:** [Webpack](https://webpack.js.org/) / [Rollup](https://rollupjs.org/) *(Integration planned in starter kits)*

## CI/CD

*   **Platform:** [GitHub Actions](https://github.com/features/actions)

## Notes

*   Dependencies marked with *(Integration planned)* or *(Development planned)* are part of the roadmap but not yet fully integrated or developed.
*   Specific versions will be pinned in `vcpkg.json` for reproducibility. 