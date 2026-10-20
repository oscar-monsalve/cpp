#include <iostream>
#include <print>
#include <cstddef>  // Provides std::size_t
#include <new>      // Provides std::nothrow

int* cloneArray(const int* source, std::size_t size) {
    if (source == nullptr || size == 0) {
        return nullptr;
    }

    int* clone = new int[size];

    for (int i = 0; i < size; ++i) {
        clone[i] = source[i];
    }

    return clone;
}

int main () {
    constexpr int ARRAY_SIZE = 10;
    int* originalArray = new (std::nothrow) int[ARRAY_SIZE];

    if (originalArray == nullptr) {
        std::println("Error: null pointer 'nullptr' found.");
        return 1;
    }

    // Fill the original array
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        originalArray[i] = i;
    }

    int* clonedArray = cloneArray(originalArray, ARRAY_SIZE);

    if (clonedArray == nullptr) {
        std::println("Error: null pointer 'nullptr' found.");
        return 1;
    }

    // =================================================================================
    // PAUSE PROGRAM TO CHECK MEMORY USAGE
    // =================================================================================
    // std::println("Memory is allocated. Check your resource monitor now!");
    // std::println("Press Enter to free the memory and exit...");
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // std::cin.get();
    // =================================================================================
    // PAUSE PROGRAM TO CHECK MEMORY USAGE
    // =================================================================================

    std::print("Original array: ");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::print("{} ", originalArray[i]);
    }

    std::println("");

    std::print("Cloned   array: ");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::print("{} ", clonedArray[i]);
    }

    std::println("");

    delete[] originalArray;
    delete[] clonedArray;
    originalArray = nullptr;
    clonedArray = nullptr;

    return 0;
}
