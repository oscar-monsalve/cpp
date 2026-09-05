// Write a program that declares an integer, stores its address in a pointer,
// and changes the integer's value through the pointer.
//
// **Requirements:**
//
// - Print the value and address before and after the modification.
// - Explain the roles of the address-of (`&`) and dereference (`*`) operators.

#include<iostream>

int main () {
    int oldNumber = 1;

    // Memory address of the variable
    int* ptr = &oldNumber;

    std::cout << "Old number's memory address: " << ptr << "\n";
    std::cout << "Old number's value: " << *ptr << "\n\n";

    int newNumber = 9;
    *ptr = newNumber;

    std::cout << "New number's memory address: " << ptr << "\n";
    std::cout << "New number's value: " << *ptr << "\n";

    return 0;
}
