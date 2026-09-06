// ## 2. Swap Two Values Using Pointers
//
// Implement a function `void swapValues(int* first, int* second)` that swaps two integers through pointers.
//
// **Requirements:**
//
// - Call the function from `main` and print the values before and after the swap.
// - Handle null pointers without crashing.

#include <print>

void swapValues(int* first, int* second) {
    // Check if the pointers are not null
    if (first == nullptr || second == nullptr) {
        std::println("Cannot swap null pointers");
        return;
    }

    int temp = *first;  // Dereferencing the pointer of the 'first' number to access its value
    *first = *second;
    *second = temp;
}

int main () {
    int first = 1;
    int second = 9;

    std::println("Swapping numbers passing pointers\n");

    std::println("'First' before swap: {}", first);
    std::println("'Second' before swap: {}\n", second);

    swapValues(&first, &second);

    std::println("'First' after swap: {}", first);
    std::println("'Second' after swap: {}", second);

    return 0;
}
