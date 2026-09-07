// ## 3. Traverse an Array With Pointer Arithmetic
//
// Create an integer array and use only pointer arithmetic, rather than array indexing, to calculate its sum,
// minimum, and maximum values.
//
// **Requirements:**
//
// - Pass the beginning and end pointers to the calculation functions.
// - Do not use expressions such as `array[index]` while traversing the array.

#include <print>
#include <iterator>
#include <stdexcept>

// All calculation functions require a valid, ordered range [startPtr, endPtr)
// within one live array; endPtr may point one past its last element.
// Equality detects an empty range, but does not validate arbitrary or dangling pointers.
// Minimum and maximum reject empty ranges; their sum is zero.
int arrMinValue(const int* startPtr, const int* endPtr) {
    // Checking for an empty range
    if (startPtr == endPtr) {
        throw std::invalid_argument("Cannot calculate the minimum of an empty range.");
    }

    int min = *startPtr;
    for (const int* current=startPtr; current < endPtr; ++current) {
        if (*current < min) {
            min = *current;
        }
    }

    return min;
}

int arrMaxValue(const int* startPtr, const int* endPtr) {
    // Checking for an empty range
    if (startPtr == endPtr) {
        throw std::invalid_argument("Cannot calculate the maximum of an empty range.");
    }

    int max = *startPtr;
    for (const int* current=startPtr; current < endPtr; ++current) {
        if (*current > max) {
            max = *current;
        }
    }

    return max;
}

// Every intermediate sum must fit in int; signed integer overflow is undefined behavior.
int arrSum(const int* startPtr, const int* endPtr) {
    int sum = 0;

    // Loop through the array until 'current' reaches 'endPtr'
    for (const int* current=startPtr; current < endPtr; ++current) {
        sum += *current;
    }

    return sum;
}

int main () {
    int numberArray1[] = {1, 2, 3, 4, 5};  // sum: 15
    int numberArray2[] = {3, 1, 5, 2, 1, 6};  // sum: 18
    int numberArray3[] = {-3, -1, -5, -2, -1, -6};  // sum: -18
    int numberArray4[] = {7};
    int numberArray5[] = {0, 0, 0};
    int numberArray6[] = {-4, 0, 7, -2};

    int arrayLength1 = std::size(numberArray1);
    int arrayLength2 = std::size(numberArray2);
    int arrayLength3 = std::size(numberArray3);
    int arrayLength4 = std::size(numberArray4);
    int arrayLength5 = std::size(numberArray5);
    int arrayLength6 = std::size(numberArray6);

    // Using the array name to create a pointer automatically decays to an int*. Using '&numberArray' in this
    // case is not correct because it creates an 'int(*)[5]' type, and a 'const int*' type is needed.
    const int* startPtr1 = numberArray1;
    const int* endPtr1 = numberArray1 + arrayLength1;  // One past the last element; do not dereference

    const int* startPtr2 = numberArray2;
    const int* endPtr2 = numberArray2 + arrayLength2;

    const int* startPtr3 = numberArray3;
    const int* endPtr3 = numberArray3 + arrayLength3;

    const int* startPtr4 = numberArray4;
    const int* endPtr4 = numberArray4 + arrayLength4;

    const int* startPtr5 = numberArray5;
    const int* endPtr5 = numberArray5 + arrayLength5;

    const int* startPtr6 = numberArray6;
    const int* endPtr6 = numberArray6 + arrayLength6;

    // Array 1
    std::println("Array 1: {}:", numberArray1);
    std::println("    Size: {}", arrayLength1);
    // Print the memory address of the array (first value). The raw pointer must be casted to a generic pointer
    // type 'void*' or 'const void*' with 'static_cast' to allow the println function to show the hex address.
    std::println("    Mem. address: {}", static_cast<const void*>(startPtr1));
    std::println("    Start value: {}", *startPtr1);
    std::println("    End value: {}", *(endPtr1 - 1));
    std::println("    Calculations:");
    std::println("        - Min. value: {}", arrMinValue(startPtr1, endPtr1));
    std::println("        - Max. value: {}", arrMaxValue(startPtr1, endPtr1));
    std::println("        - Sum of all array values: {}\n", arrSum(startPtr1, endPtr1));

    // Array 2
    std::println("Array 2: {}:", numberArray2);
    std::println("    Size: {}", arrayLength2);
    std::println("    Mem. address: {}", static_cast<const void*>(startPtr2));
    std::println("    Start value: {}", *startPtr2);
    std::println("    End value: {}", *(endPtr2 - 1));
    std::println("    Calculations:");
    std::println("        - Min. value: {}", arrMinValue(startPtr2, endPtr2));
    std::println("        - Max. value: {}", arrMaxValue(startPtr2, endPtr2));
    std::println("        - Sum of all array values: {}\n", arrSum(startPtr2, endPtr2));

    // Array 3
    std::println("Array 3: {}:", numberArray3);
    std::println("    Size: {}", arrayLength3);
    std::println("    Mem. address: {}", static_cast<const void*>(startPtr3));
    std::println("    Start value: {}", *startPtr3);
    std::println("    End value: {}", *(endPtr3 - 1));
    std::println("    Calculations:");
    std::println("        - Min. value: {}", arrMinValue(startPtr3, endPtr3));
    std::println("        - Max. value: {}", arrMaxValue(startPtr3, endPtr3));
    std::println("        - Sum of all array values: {}\n", arrSum(startPtr3, endPtr3));

    // Array 4
    std::println("Array 4: {}:", numberArray4);
    std::println("    Size: {}", arrayLength4);
    std::println("    Mem. address: {}", static_cast<const void*>(startPtr4));
    std::println("    Start value: {}", *startPtr4);
    std::println("    End value: {}", *(endPtr4 - 1));
    std::println("    Calculations:");
    std::println("        - Min. value: {}", arrMinValue(startPtr4, endPtr4));
    std::println("        - Max. value: {}", arrMaxValue(startPtr4, endPtr4));
    std::println("        - Sum of all array values: {}\n", arrSum(startPtr4, endPtr4));

    // Array 5
    std::println("Array 5: {}:", numberArray5);
    std::println("    Size: {}", arrayLength5);
    std::println("    Mem. address: {}", static_cast<const void*>(startPtr5));
    std::println("    Start value: {}", *startPtr5);
    std::println("    End value: {}", *(endPtr5 - 1));
    std::println("    Calculations:");
    std::println("        - Min. value: {}", arrMinValue(startPtr5, endPtr5));
    std::println("        - Max. value: {}", arrMaxValue(startPtr5, endPtr5));
    std::println("        - Sum of all array values: {}\n", arrSum(startPtr5, endPtr5));

    // Array 6
    std::println("Array 6: {}:", numberArray6);
    std::println("    Size: {}", arrayLength6);
    std::println("    Mem. address: {}", static_cast<const void*>(startPtr6));
    std::println("    Start value: {}", *startPtr6);
    std::println("    End value: {}", *(endPtr6 - 1));
    std::println("    Calculations:");
    std::println("        - Min. value: {}", arrMinValue(startPtr6, endPtr6));
    std::println("        - Max. value: {}", arrMaxValue(startPtr6, endPtr6));
    std::println("        - Sum of all array values: {}\n", arrSum(startPtr6, endPtr6));


    // Testing empty ranges
    std::println("Testing empty ranges:\n");
    int numbers[] = {3, 1, 5};

    try {
        int min = arrMinValue(numbers, numbers);
        std::println("Minimum: {}", min);
    } catch (const std::invalid_argument& error) {
        std::println("Error: {}", error.what());
    }

    try {
        int min = arrMaxValue(numbers, numbers);
        std::println("Maximum: {}", min);
    } catch (const std::invalid_argument& error) {
        std::println("Error: {}", error.what());
    }

    // Testing the sum of empty ranges. Should return 0.
    try {
        int sum = arrSum(numbers, numbers);
        std::println("sum: {}", sum);
    } catch (const std::invalid_argument& error) {
        std::println("Error: {}", error.what());
    }

    return 0;
}
