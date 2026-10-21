#include <iostream>
#include <print>
#include <cstddef>  // Provides std::size_t
#include <new>      // Provides std::nothrow

int* cloneArray(const int* source, std::size_t size) {
    if (source == nullptr || size == 0) {
        return nullptr;
    }

    int* clone = new (std::nothrow) int[size];
    if (clone == nullptr) {
        return nullptr;
    }

    for (std::size_t i = 0; i < size; ++i) {
        clone[i] = source[i];
    }

    return clone;
}

// Compare the elements of each arrray. Return true if they have the same elements
bool equalArrays(const int* originalArray, const int* clonedArray, std::size_t arraySize) {
    for (std::size_t i = 0; i < arraySize; ++i) {
        if (originalArray[i] != clonedArray[i]) {
            return false;
        }
    }
    return true;
}

int main () {
    constexpr std::size_t ARRAY_SIZE = 100'000'000;

    int* originalArray = new (std::nothrow) int[ARRAY_SIZE];
    if (originalArray == nullptr) {
        std::println("Error: null pointer 'nullptr' found.");
        return 1;
    }

    // Fill the original array
    for (std::size_t i = 0; i < ARRAY_SIZE; ++i) {
        originalArray[i] = i;
    }

    // Check memory usage before cloning the original array
    std::println("Original array initialized. Check memory usage.");
    std::println("Press Enter to continue...");
    std::cin.get();

    // Uncomment the following to test edge cases
    // int* clonedArray = cloneArray(nullptr, ARRAY_SIZE);  // Should return nullptr
    // int* clonedArray = cloneArray(originalArray, 0);    // Should return nullptr


    int* clonedArray = cloneArray(originalArray, ARRAY_SIZE);
    if (clonedArray == nullptr) {
        std::println("Error: null pointer 'nullptr' found.");
        delete[] originalArray;  // Release the original allocation before returning
        return 1;
    }

    // Verify equality before modifying the clone
    // If they are not equal, it mean the copy was not succesfull
    // Then should delete the allocated memory and return early
    if (!equalArrays(originalArray, clonedArray, ARRAY_SIZE)) {
        std::println("Error: the clone does not match the original.");
        delete[] originalArray;
        delete[] clonedArray;
        return 1;
    }

    std::println("Verified: the clone initially matches the original.\n");

    // Modify the cloned array duplicating each element of the original array
    for (std::size_t i = 0; i < ARRAY_SIZE; ++i) {
        clonedArray[i] *= 2;
    }

    // Check memory after succesfull cloning
    std::println("Both arrays are allocated. Check memory usage again.");
    std::println("Press Enter to continue...");
    std::cin.get();

    std::print("Original array: ");
    std::print("{{ ");
    for (std::size_t i = 0; i < ARRAY_SIZE; ++i) {
        std::print("{} ", originalArray[i]);
    }
    std::print("}}");
    std::println();

    std::print("Cloned   array: ");
    std::print("{{ ");
    for (std::size_t i = 0; i < ARRAY_SIZE; ++i) {
        std::print("{} ", clonedArray[i]);
    }
    std::print("}}");
    std::println("\n");

    // Report if the arrays are equal or not after modifying the cloned array
    bool areEqualArrays = equalArrays(originalArray, clonedArray, ARRAY_SIZE);
    if (areEqualArrays) {
        std::println("The original and cloned arrays have the same elements.");
    } else {
        std::println("The original and cloned arrays have different elements.");
    }


    delete[] originalArray;
    delete[] clonedArray;
    originalArray = nullptr;
    clonedArray = nullptr;

    return 0;
}
