#include <print>    // Required for std::print and std::println
#include <tuple>
#include <vector>

int main() {
    // 1. C++23/26 Printing System
    // Fully type-safe, replaces std::cout and std::printf completely
    std::println("--- Testing Modern Printing ---");
    std::println("Hello C++26 World!");
    std::println("Formatted Pi: {:.4f}", 3.14159265);

    // C++26 exclusive feature: std::println() can now be called completely empty
    // to print a single blank newline (P3142R0). In C++23, you had to pass an empty string "".
    std::println();

    // 2. C++26 Feature: Unnamed Placeholder Variables (_)
    // Allows declaring multiple identical variables in the same scope to discard elements
    std::println("--- Testing C++26 Placeholder Variables ---");
    auto [_, target, _] = std::make_tuple("Trash data A", 999, "Trash data B");
    std::println("Successfully extracted target value: {}", target);
    std::println();

    // 3. C++26 Feature: Upper/Lowercase and Padding Improvements to Pointer Formatting
    // C++26 introduced specific format rules for raw memory locations and nullptrs
    std::println("--- Testing C++26 Pointer Formatting ---");
    int data_node = 42;
    int* ptr = &data_node;

    std::println("Uppercase hex pointer: {:P}", (void*)ptr);
    std::println("Padded nullptr representation: {:016}", nullptr);

    return 0;
}
