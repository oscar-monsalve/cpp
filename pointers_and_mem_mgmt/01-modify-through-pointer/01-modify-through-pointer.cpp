// Write a program that declares an integer, stores its address in a pointer,
// and changes the integer's value through the pointer.
//
// **Requirements:**
//
// - Print the value and address before and after the modification.
// - Explain the roles of the address-of (`&`) and dereference (`*`) operators.

#include <print>

int main () {
    int oldNumber = 1;

    // Memory address of the variable
    int* ptr = &oldNumber;

    std::println("Old number's memory address: {}", static_cast<const void*>(ptr));
    std::println("Old number's value: {}", *ptr);
    std::println();

    int newNumber = 9;
    *ptr = newNumber;

    std::println("New number's memory address: {}", static_cast<const void*>(ptr));
    std::println("New number's value: {}", *ptr);

    return 0;
}
