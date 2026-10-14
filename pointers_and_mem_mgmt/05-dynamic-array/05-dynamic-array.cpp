#include <iostream>
#include <print>
#include <new>


int main () {
    // Definition of the maximum array size of integers (int). The maximum allows size is 100 million.
    // 100 million ints = 100 MB (int -> 32 bits -> 4 bytes; 4 bytes * 100'000'000 = 100 MB)
    constexpr unsigned int MAX_ARRAY_SIZE = 100'000'000;
    unsigned int arrayInputSize{};

    std::println("Enter the amount of integers (int) you want to store in an array. The maximum is 100 million: ");
    if (!(std::cin >> arrayInputSize)) {
        std::println("Error: enter a positive integer greater than zero.");
        return 1;
    }
    if (arrayInputSize == 0) {
        std::println("Error: array size cannot be zero. Enter a valid size.");
        return 1;
    } else if (arrayInputSize > MAX_ARRAY_SIZE) {
        std::println(
            "The maximum array size is {}, which equals to a maximum requested memory of 100 MB.",
            MAX_ARRAY_SIZE
        );
        return 1;
    }

    return 0;
}
