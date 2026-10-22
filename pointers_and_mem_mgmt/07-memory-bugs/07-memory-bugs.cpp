#include <print>
#include <cstddef>  // Provides std::size_t
#include <new>      // Provides std::nothrow

int main () {
    // 1. Memory leak
    {
        std::println("1. Memory leak example.");
        int* leak = new (std::nothrow) int(42);
        if (leak == nullptr) {
            std::println("Error: null pointer 'nullptr' found.");
            return 1;
        }

        std::println("The allocated number is: {}", *leak);
        std::println("Stored in address: {}\n", static_cast<const void*>(leak));

        std::println("Problem: memory has not been deleted. It would produce a memory leak when it goes out of scope.");

        // TODO: how to simulate the pointer going out of scope and using again so it because unreachable?
    }


    // 2. Dangling pointer
    {
        std::println("\n2. Dangling pointer example.");
        int* dangling = new (std::nothrow) int(42);
        if (dangling == nullptr) {
            std::println("Error: null pointer 'nullptr' found.");
            return 1;
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



    return 0;
}
