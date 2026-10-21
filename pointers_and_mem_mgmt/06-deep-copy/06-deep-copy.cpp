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

// Compare the elements of each array. Return true if they have the same elements
bool equalArrays(const int* originalArray, const int* clonedArray, std::size_t arraySize) {
    for (std::size_t i = 0; i < arraySize; ++i) {
        if (originalArray[i] != clonedArray[i]) {
            return false;
        }
    }
    return true;
}

int main () {
    constexpr std::size_t ARRAY_SIZE = 200;

    // Test edge cases for cloneArray() function
    int sample = 42;

    int* nullSourceResult = cloneArray(nullptr, 3);
    int* zeroSizeResult = cloneArray(&sample, 0);
    int* bothEmptyResult = cloneArray(nullptr, 0);

    bool edgeCasesPassed =
        nullSourceResult == nullptr &&
        zeroSizeResult == nullptr &&
        bothEmptyResult == nullptr;

    std::println("Null source test: {}", nullSourceResult == nullptr ? "PASS" : "FAIL");
    std::println("Zero size test: {}", zeroSizeResult == nullptr ? "PASS" : "FAIL");
    std::println("Null source and zero size test: {}", bothEmptyResult == nullptr ? "PASS" : "FAIL");

    // delete[] nullptr is safe
    delete[] nullSourceResult;
    delete[] zeroSizeResult;
    delete[] bothEmptyResult;

    if (!edgeCasesPassed) {
        return 1;
    }
    std::println();

    // Keep going with the exercise after the tests
    int* originalArray = new (std::nothrow) int[ARRAY_SIZE];
    if (originalArray == nullptr) {
        std::println("Error: null pointer 'nullptr' found.");
        return 1;
    }

    // Fill the original array
    for (std::size_t i = 0; i < ARRAY_SIZE; ++i) {
        originalArray[i] = static_cast<int>(i);  // Cast i of type 'size_t' to match the array values 'int'
    }

    // Check memory usage before cloning the original array
    std::println("Original array initialized. Check memory usage.");
    std::println("Press Enter to continue...");
    std::cin.get();

    int* clonedArray = cloneArray(originalArray, ARRAY_SIZE);
    if (clonedArray == nullptr) {
        std::println("Error: null pointer 'nullptr' found.");
        delete[] originalArray;  // Release the original allocation before returning
        return 1;
    }

    // Verify equality before modifying the clone
    // If they are not equal, it mean the copy was not succesful
    // Then should delete the allocated memory and return early
    if (!equalArrays(originalArray, clonedArray, ARRAY_SIZE)) {
        std::println("Error: the clone does not match the original.");
        delete[] originalArray;
        delete[] clonedArray;
        return 1;
    }

    std::println("Verified: the clone initially matches the original.\n");

    // Modify the cloned array doubling each element's value
    for (std::size_t i = 0; i < ARRAY_SIZE; ++i) {
        clonedArray[i] *= 2;
    }

    // Check if the original array was not changed
    bool originalUnchanged = true;
    for (std::size_t i; i < ARRAY_SIZE; ++i) {
        if (originalArray[i] != static_cast<int>(i)) {
            originalUnchanged = false;
            break;
        }
    }
    std::println("Original unchanged: {}\n", originalUnchanged ? "PASS" : "FAIL");

    // Check memory after succesfull cloning
    std::println("Both arrays are allocated. Check memory usage again.");
    std::println("Press Enter to continue...");
    std::cin.get();

    std::print("Original array: ");
    std::print("{{ ");
    for (std::size_t i = 0; i < ARRAY_SIZE; ++i) {
        std::print("{} ", originalArray[i]);
    }
    std::println("}}\n");

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

    if (!originalUnchanged) {
        return 1;  // Failure: the original array was modified.
    }

    return 0;
}
