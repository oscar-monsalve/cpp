#include <cstdio>
#include <print>
#include <cstddef>  // Provides std::size_t
#include <new>      // Provides std::nothrow


void memoryLeak() {
    std::println("1. Memory leak example:\n");

    int* allocNumber = new (std::nothrow) int(42);
    if (allocNumber == nullptr) {
        return;
    }

    std::println("The allocated number is: {}", *allocNumber);
    std::println("Stored in address: {}\n", static_cast<const void*>(allocNumber));

    std::println(
        "Problem: memory has not been deleted. It would produce a memory leak when it goes out of scope."
    );
    // TODO: how to simulate the pointer going out of scope and using it again so it becomes unreachable?
    // Install gf2 debugger on the desktop pc
}

void danglePointer() {
    // 2. Dangling pointer
    std::println("\n2. Dangling pointer example.");
    int* dangling = new (std::nothrow) int(42);
    if (dangling == nullptr) {
        std::println("Error: null pointer 'nullptr' found.");
        return;
    }

    std::println("The allocated number is: {}", *dangling);
    std::println("Stored in address: {}\n", static_cast<const void*>(dangling));

    delete dangling;

    std::println("Memory has been deleted. The pointer to the memory does not exists anymore.");
    std::println("Should it be used again, a memory error would occur.");
    std::println("For example, it is used again to print the number and its memory address.");
    std::println("The number is not the correct one, but the address is still the same.\n");

    std::println("The allocated number is: {}", *dangling);
    std::println("Stored in address: {}", static_cast<const void*>(dangling));
}

void doubleDeletion();
void mismatchedNewDelete();


int main () {
    // Ex. 1: memory leak
    memoryLeak();

    return 0;
}
