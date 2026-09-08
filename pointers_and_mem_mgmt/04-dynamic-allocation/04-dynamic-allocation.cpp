// ## 4. Dynamically Allocate a Single Object
//
// Dynamically allocate an integer, read its value from standard input, print it, and release the allocated memory.
//
// **Requirements:**
//
// - Use `new` and `delete`.
// - Set the pointer to `nullptr` after deleting the object.
// - Describe what could happen if the memory were not released.
//
// References: https://cplusplus.com/doc/tutorial/dynamic/

#include <iostream>
#include <print>
#include <cstdlib>
#include <iterator>
#include <cassert>

int main () {
    int reqMemByUser;
    int* ptr;

    std::print("Enter a positive integer: ");

    std::cin >> reqMemByUser;

    std::println("Your input is: {}", userInput);

    ptr = new int(reqMemByUser);

    return 0;
}
