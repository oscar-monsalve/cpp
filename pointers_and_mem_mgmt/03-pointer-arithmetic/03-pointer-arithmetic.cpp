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

int arrMinValue(int* startPtr) {
    return *startPtr;
}

int arrMaxValue(int* endPtr) {
    return *endPtr - 1;
}

int arrSum(int* startPtr, int* endPtr) {
    int sum = 0;

    // Loop through the array as long as startPtr has not reached endPtr
    while (startPtr < endPtr) {
        sum += *startPtr;
    }

    return sum;
}

int main () {
    int numberArray[] = {1, 2, 3, 4, 5};
    int arrayLength = std::size(numberArray);

    // Using the array name to create a pointer automatically decays to an int*. Using '&numberArray' is wrong:
    // it creates an 'int(*)[5]' type
    int* startPtr = numberArray;
    int* endPtr = numberArray + arrayLength;  // One past the end of the array

    // Print the memory address of the array (first value). The raw pointer must be casted to a generic pointer
    // type 'void*' or 'const void*' with 'static_cast'
    // to allow the println function to show the hex address.
    std::println("Array size: {}\n", arrayLength);

    std::println("Array pointer mem. address: {}", static_cast<void*>(startPtr));
    std::println("Start array pointer value: {}", *startPtr);
    std::println("End array pointer value: {}\n", *endPtr);

    std::println("Solution:");
    std::println("Array min. value: {}", arrSum(startPtr, endPtr));
    std::println("Array max. value: {}", arrMinValue(startPtr));
    std::println("Array sum of values: {}", arrMaxValue(endPtr));

    return 0;
}
