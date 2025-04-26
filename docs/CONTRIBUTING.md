# Contributing to CoreWeb

Thank you for your interest in contributing to CoreWeb! We welcome contributions from everyone.

## How to Contribute

*   **Reporting Bugs:** Use the [Bug Report](https://github.com/emiliancristea/CoreWeb/issues/new?assignees=&labels=bug&template=bug_report.md&title=%5BBug%5D%3A+) issue template.
*   **Suggesting Enhancements:** Use the [Feature Request](https://github.com/emiliancristea/CoreWeb/issues/new?assignees=&labels=enhancement&template=feature_request.md&title=%5BFeature%5D%3A+) issue template.
*   **Submitting Plugins:** Use the [Plugin Submission](https://github.com/emiliancristea/CoreWeb/issues/new?assignees=&labels=plugin%2Csubmission&template=plugin_submission.md&title=%5BPlugin%5D%3A+) issue template.
*   **Pull Requests:** For code changes, please follow the guidelines below.

## Pull Request Process

1.  Ensure any install or build dependencies are removed before the end of the layer when doing a build.
2.  Update the README.md with details of changes to the interface, this includes new environment variables, exposed ports, useful file locations and container parameters.
3.  Increase the version numbers in any examples files and the README.md to the new version that this Pull Request would represent. The versioning scheme we use is [SemVer](http://semver.org/).
4.  You may merge the Pull Request in once you have the sign-off of two other developers, or if you do not have permission to do that, you may request the second reviewer to merge it for you.

## Development Workflow

1.  Fork the repository.
2.  Create a new branch for your feature or bug fix: `git checkout -b feat/your-feature-name` or `git checkout -b fix/your-bug-fix`.
3.  Make your changes, adhering to the coding style and commit message format.
4.  Add tests for your changes.
5.  Ensure all tests pass.
6.  Commit your changes using the Conventional Commits format (see below).
7.  Push your branch to your fork.
8.  Submit a Pull Request to the main repository.

## Code Style

*   **C++:** Follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
    *   We will use `clang-format` and `clang-tidy` (configured later) to enforce style.
*   **CMake:** Follow standard CMake best practices.
*   **Frontend (JS/TS):** *(Style guide to be determined - likely Prettier)*
*   **Markdown:** Use consistent formatting.

## Commit Message Format

We follow the [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/) specification. This helps automate changelog generation and makes the commit history easier to read.

**Format:**

```
<type>[optional scope]: <description>

[optional body]

[optional footer(s)]
```

**Example:**

```
feat(cli): add 'create' command to scaffold new projects

Implements the initial 'coreweb create <app-name>' command.

Generates the basic directory structure and a placeholder coreweb.toml file.

Fixes #12
```

**Common Types:**

*   `feat`: A new feature
*   `fix`: A bug fix
*   `docs`: Documentation only changes
*   `style`: Changes that do not affect the meaning of the code (white-space, formatting, missing semi-colons, etc)
*   `refactor`: A code change that neither fixes a bug nor adds a feature
*   `perf`: A code change that improves performance
*   `test`: Adding missing tests or correcting existing tests
*   `build`: Changes that affect the build system or external dependencies (example scopes: cmake, vcpkg)
*   `ci`: Changes to our CI configuration files and scripts (example scopes: github-actions)
*   `chore`: Other changes that don't modify src or test files

## Code of Conduct

Please note that this project is released with a Contributor Code of Conduct (`CODE_OF_CONDUCT.md`). By participating in this project you agree to abide by its terms. 