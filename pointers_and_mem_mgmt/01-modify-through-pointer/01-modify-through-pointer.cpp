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
    int* ptrOldNumber = &oldNumber;  // The operator '&' enables to get the memory address of the variable.

    std::println("Memory address before modification: {}", static_cast<const void*>(ptrOldNumber));
    // The '*' operator (preceding the variable name) allows to "dereference" the pointer, which enables access
    // to the value of the variable, not the memory address.
    std::println("Value before modification: {}", *ptrOldNumber);
    std::println();

    *ptrOldNumber = 9;

    // The value of 'oldNumber' changed, but the memory address does not.
    std::println("Memory address after modification: {}", static_cast<const void*>(ptrOldNumber));
    std::println("Value after modification: {}", *ptrOldNumber);

    return 0;
}
