#include <iostream>
#include <print>
#include <new>      // Provides std::nothrow
#include <numeric>  // Provides std::accumulate()
#include <limits>   // Provides std::numeric_limits


int main () {
    // Definition of the maximum array size of integers (int). The maximum allows size is 100 million.
    // 100 million ints = ~400 MB (int -> 32 bits -> 4 bytes. Then 4 bytes * 100'000'000 = 400 MB)
    constexpr int MAX_ARRAY_SIZE = 100'000'000;
    int arrayInputSize{};

    std::println("Enter the array size to store integers. The maximum value is 100 million: ");

    if (!(std::cin >> arrayInputSize)) {
        std::println("Error: enter a positive integer number.");
        return 1;
    }

    if (arrayInputSize <= 0) {
        std::println("Error: array size cannot be negative or zero. Enter a valid size.");
        return 1;
    } else if (arrayInputSize > MAX_ARRAY_SIZE) {
        std::println(
            "The maximum array size is {}, which equals to a maximum requested memory of 400 MB.",
            MAX_ARRAY_SIZE
        );
        return 1;
    }

    // Allocate the requested block of memory
    int* ptr = new (std::nothrow) int[arrayInputSize];

    if (ptr == nullptr) {
        std::println("Error assigning memory. NUll pointer 'nullptr' found.");
        return 1;
    }

    // Fill the array sequencially
    for (int i = 0; i < arrayInputSize; ++i) {
        ptr[i] = i;
    }

    // Passing 0.0 forces std::accumulate to use double internally, preventing overflow
    double average = std::accumulate(ptr, ptr + arrayInputSize, 0.0) / static_cast<double>(arrayInputSize);

    std::println("The array average is: {}", average);

    // =================================================================================
    // PROGRAM PAUSE & VISUAL RESOURCE MONITORING
    // =================================================================================
    std::println("Memory is allocated. Check your resource monitor now!");
    std::println("Press Enter to free the memory and exit...");

    // 1. Clear leftover newline characters from the input buffer.
    // When 'std::cin >> arrayInputSize' read the size, it left the 'Enter' key ('\n')
    // behind in the buffer. This line discards all characters up to the maximum
    // possible stream size until it consumes that trailing newline, preventing
    // the subsequent pause command from instantly skipping ahead.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // 2. Halt the execution.
    // Because the buffer is now completely empty, 'std::cin.get()' forces the
    // program to freeze and wait for a fresh keypress (Enter) from the user.
    std::cin.get();

    // NOTE ON SYSTEM RESOURCE MONITORING (~385 MB):
    // You will notice the Resource Monitor reports ~385 MB rather than exactly 400 MB.
    // - 100,000,000 ints * 4 bytes = 400,000,000 bytes.
    // - Operating systems calculate Binary Megabytes (MiB) by dividing by 1024 twice:
    //   400,000,000 / 1024 / 1024 = 381.47 MiB.
    // - The remaining ~3.5 MB up to 385 MB is standard runtime memory overhead
    //   consumed by the C++ executable itself (code segment, standard libraries, etc.).
    // =================================================================================

    // Release the allocated block of memory with new[]
    delete[] ptr;

    // Clear the dangling pointer
    ptr = nullptr;

    return 0;
}
