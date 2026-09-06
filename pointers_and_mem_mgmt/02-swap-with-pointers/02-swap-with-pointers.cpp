// ## 2. Swap Two Values Using Pointers
//
// Implement a function `void swapValues(int* first, int* second)` that swaps two integers through pointers.
//
// **Requirements:**
//
// - Call the function from `main` and print the values before and after the swap.
// - Handle null pointers without crashing.

#include <iostream>

void swapValues(int* first, int* second) {
    if (first == nullptr || second == nullptr) {
        std::cout << "Null pointer found: " << first << second << "\n";
        std::cout << "Exiting safely." << first << second << "\n";
        return;
    }

    int* x = second;
}

int main () {
    int first = 1;
    int second = 9;

    std::cout << "First before: " << first << "\n";

    return 0;
}
