// Temporary file to verify CMake + vcpkg integration
#include <iostream>
#include <nlohmann/json.hpp>
#include <gtest/gtest.h>

int main() {
    nlohmann::json j = {{"pi", 3.141}};
    std::cout << "Hello from verification target! JSON: " << j.dump() << std::endl;
    // Simple GTEST assertion just to ensure linking works
    ASSERT_TRUE(true);
    return 0;
} 