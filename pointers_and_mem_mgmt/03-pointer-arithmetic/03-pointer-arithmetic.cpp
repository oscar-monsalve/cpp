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

int arrMinValue(const int* startPtr, const int* endPtr) {
    int min = *startPtr;
    for (const int* current=startPtr; current < endPtr; ++current) {
        if (*current < min) {
        }
    }
}

// int arrMaxValue(const int* startPtr, const int* endPtr) {
//     for (const int* current=startPtr; current < endPtr; ++current) {
//     }
// }

int arrSum(const int* startPtr, const int* endPtr) {
    int sum = 0;

    // Loop through the array until 'current' reaches 'endPtr'
    for (const int* current=startPtr; current < endPtr; ++current) {
        sum += *current;
    }

    return sum;
}

int main () {
    int numberArray1[] = {1, 2, 3, 4, 5};
    int numberArray2[] = {3, 1, 5, 2, 1, 6};  // sum: 18

    int arrayLength1 = std::size(numberArray1);
    int arrayLength2 = std::size(numberArray2);

    // Using the array name to create a pointer automatically decays to an int*. Using '&numberArray' in this
    // case is not correct because it creates an 'int(*)[5]' type, and a 'const int*' type is needed.
    const int* startPtr1 = numberArray1;
    const int* endPtr1 = numberArray1 + arrayLength1;  // Past element of the array

    const int* startPtr2 = numberArray2;
    const int* endPtr2 = numberArray2 + arrayLength2;

    // Array 1
    std::println("Array 1: {}:", numberArray1);
    std::println("    Size: {}", arrayLength1);
    // Print the memory address of the array (first value). The raw pointer must be casted to a generic pointer
    // type 'void*' or 'const void*' with 'static_cast' to allow the println function to show the hex address.
    std::println("    Mem. address: {}", static_cast<const void*>(startPtr1));
    std::println("    Start value: {}", *startPtr1);
    std::println("    End value: {}", *(endPtr1 - 1));
    std::println("    Calculations:");
    // std::println("Min. value: {}", arrMinValue(startPtr));
    // std::println("Max. value: {}", arrMaxValue(endPtr));
    std::println("        - Sum of all array values: {}\n", arrSum(startPtr1, endPtr1));


    // Array 2
    std::println("Array 2: {}:", numberArray2);
    std::println("    Size: {}", arrayLength2);
    std::println("    Mem. address: {}", static_cast<const void*>(startPtr2));
    std::println("    Start value: {}", *startPtr2);
    std::println("    End value: {}", *(endPtr2 - 1));
    std::println("    Calculations:");
    // std::println("Min. value: {}", arrMinValue(startPtr2));
    // std::println("Max. value: {}", arrMaxValue(endPtr2));
    std::println("        - Sum of all array values: {}\n", arrSum(startPtr2, endPtr2));


    return 0;
}
