#include <cstdio>
#include <print>
#include <cstddef>  // Provides std::size_t
#include <new>      // Provides std::nothrow


void memoryLeak() {
    std::println("1. Memory leak example:\n");

    int* allocNumber = new (std::nothrow) int(42);
    if (allocNumber == nullptr) {
        std::println("Allocation failed. Returning.");
        return;
    }

    std::println("The allocated number is: {}", *allocNumber);
    std::println("Address: {}\n", static_cast<const void*>(allocNumber));

    std::println(
        "Problem: memory has not been deleted. It would produce a memory leak when it goes out of scope.\n"
    );

    // Intentionally omitting the 'delete' operator.

    // The solution to the leak is to call 'delete':
    // delete allocNumber;

} // The local pointer disappears; the allocated integer remains alive.

void danglePointer() {
    // 2. Dangling pointer
    std::println("\n2. Dangling pointer example:\n");

    int* number = new (std::nothrow) int(42);
    if (number == nullptr) {
        std::println("Allocation failed. Returning.");
        return;
    }

    std::println("The allocated number is: {}", *number);
    std::println("Address: {}\n", static_cast<const void*>(number));

    delete number;     // Ends the object's lifetime and releases its storage.
    number = nullptr;  // Clears this pointer's dangling address.

    if (number == nullptr) {
        std::println("The object has been deleted; the pointer cannot be dereferenced.\n");
    }

    // WRONG: dereferencing after delete is use-after-free.
    // std::println("{}", *number);
}

void doubleDeletion();
void mismatchedNewDelete();


int main () {
    // 1. Memory leak example
    memoryLeak();
    // The allocation is now unreachable through our program's pointers.

    // 2. Dangling pointer example
    // danglePointer();

    return 0;
}
