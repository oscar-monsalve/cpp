#include <print>
#include <cstddef>  // Provides std::size_t
#include <new>      // Provides std::nothrow

int* cloneArray(const int* source, std::size_t size) {
    if (source == nullptr || source == 0) {
        return nullptr;
    }
}

int main () {
    constexpr int ARRAY_SIZE = 100'000'000;
    int* ptr = new (std::nothrow) int[ARRAY_SIZE];

    if (ptr == nullptr) {
        std::println("Error: null pointer 'nullptr' found.");
        return 1;
    }

    delete[] ptr;
    ptr = nullptr;

    return 0;
}
