// Compilation commands to use AddressSanitizer:
// clang++ -g -O1 -fsanitize=address -fno-omit-frame-pointer 07-memory-bugs.cpp -o 07-memory-bugs-asan
// Then:
// ASAN_OPTIONS=detect_leaks=1 ./07-memory-bugs-asan

#include <print>
#include <new>      // Provides std::nothrow


void memoryLeak() {
    std::println("1. Memory leak example:");

    int* allocNumber = new (std::nothrow) int(420);
    if (allocNumber == nullptr) {
        std::println("Allocation failed. Returning.");
        return;
    }

    std::println("The allocated number is: {}", *allocNumber);
    std::println("Address: {}", static_cast<const void*>(allocNumber));

    std::println(
        "Without delete, the allocation would leak when the last pointer to it goes out of scope.\n"
    );

    // Omitting delete would leave the allocation unreachable when this function returns.
    // Solution: release the allocated memory before the local pointer goes out of scope.
    delete allocNumber;

} // The local pointer goes out of scope; the allocated integer has already been deleted.

void danglePointer() {
    // 2. Dangling pointer
    std::println("2. Dangling pointer example:");

    int* number = new (std::nothrow) int(420);
    if (number == nullptr) {
        std::println("Allocation failed. Returning.");
        return;
    }

    std::println("The allocated number is: {}", *number);
    std::println("Address: {}", static_cast<const void*>(number));

    delete number;     // Ends the object's lifetime and releases its storage.
    // Dereferencing number here would be use-after-free (undefined behavior).
    number = nullptr;  // Clears this pointer's dangling address.

    if (number == nullptr) {
        std::println("The object has been deleted; the pointer cannot be dereferenced.\n");
    }

    // The following is WRONG: number is now null, so this would be a null-pointer dereference.
    // This also causes undefined behavior.
    // std::println("{}", *number);
}

void doubleDeletion() {
    std::println("3. Double deletion example:");

    int* number = new (std::nothrow) int(420);
    if (number == nullptr) {
        return;
    }

    std::println("Hello from 'doubleDeletion'. Allocated number: {}\n", *number);

    delete number;

    // Uncommenting the following would delete the same allocation a second time.
    // It causes undefined behavior; AddressSanitizer can diagnose the double-free.
    // delete number;
}

void mismatchedNewDelete() {
    std::println("4. Mismatched new-delete example:");
    int* number = new (std::nothrow) int[69];
    if (number == nullptr) {
        return;
    }

    std::println("Hello from 'mismatchedNewDelete'.\n");

    // Problem: this is a mismatched deletion because an array was allocated, not a single object.
    // delete number;

    // Solution: use 'delete[]' to correctly pair it with the previous allocation.
    delete[] number;
}


int main () {
    // 1. Memory leak example
    memoryLeak();

    // 2. Dangling pointer example
    danglePointer();

    // 3. Double deletion
    doubleDeletion();

    // 4. Mismatched new-delete
    mismatchedNewDelete();

    return 0;
}
