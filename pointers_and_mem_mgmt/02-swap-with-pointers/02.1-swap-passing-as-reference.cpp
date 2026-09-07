// Exercise 02.1: Swap by Reference
//
// Rewrite the swapValues function so that it accepts two integers by reference
// instead of receiving pointers. Update the call in main accordingly, and print
// the values before and after the swap to verify the result.
//
// Passing references is preferred here because the function requires two valid
// integers and references cannot be null.

#include <print>

void swapValues(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}

int main () {
    int first = 1;
    int second = 9;

    std::println("Swapping numbers passing references\n");

    std::println("'First' before swap: {}", first);
    std::println("'Second' before swap: {}\n", second);

    swapValues(first, second);

    std::println("'First' after swap: {}", first);
    std::println("'Second' after swap: {}", second);

    return 0;
}
