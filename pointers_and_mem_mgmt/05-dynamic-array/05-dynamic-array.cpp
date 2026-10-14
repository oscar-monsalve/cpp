#include <iostream>
#include <print>
#include <new>


int main () {
    // Definition of the maximum array size of integers (int). The maximum allows size is 100 million.
    // 100 million ints = 100 MB (int -> 32 bits -> 4 bytes. Then 4 bytes * 100'000'000 = 100 MB)
    constexpr int MAX_ARRAY_SIZE = 100'000'000;
    int arrayInputSize{};

    std::println("Enter the array size to store integers. The maximum value is 100 million: ");

    if (!(std::cin >> arrayInputSize)) {
        std::println("Error: enter a positive integer number.");
        return 1;
    }

    if (arrayInputSize <= 0) {
        std::println("Error: array size cannot be negative or zero. Enter a valid size.");
        return 1;
    } else if (arrayInputSize > MAX_ARRAY_SIZE) {
        std::println(
            "The maximum array size is {}, which equals to a maximum requested memory of 100 MB.",
            MAX_ARRAY_SIZE
        );
        return 1;
    }

    int* ptr = new (std::nothrow) int[arrayInputSize];

    if (ptr == nullptr) {
        std::println("Error: null pointer found.");
        return 1;
    }

    return 0;
}
