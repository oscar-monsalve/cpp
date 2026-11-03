#include <print>
#include <new>          // Provides 'std::nothrow'
#include <cstddef>      // Provides 'size_t'
// #include <string_view>  // Provides 'std::string_view'
// #include <utility>      // Provides 'std::move()'


class Buffer {
public:
    const std::size_t arraySize;

    Buffer(std::size_t arraySize) : arraySize(arraySize) {

        // Prevent double-free error when trying to copy the object before calling 'new'
        // Move the original pointer to a new one
        if (array == nullptr) {
            std::println("Can't copy the object.");
            return;
        }

        array = new (std::nothrow) char[arraySize];
        if (array == nullptr) {
            std::println("Allocation failed. Returning");
            return;
        }

        // Fill the array with the letters a to z
        for (std::size_t i = 0; i < arraySize; ++i) {
            array[i] = static_cast<char>('a' + i);
        }
    }

    ~Buffer() {
        delete[] array;
    }

    const void readElements() {  // readElements() can be const, since it does not modify the buffer
        if (array == nullptr) return;

        std::println("Array elements:");
        for (std::size_t i = 0; i < arraySize ; ++i) {
            std::print("{} ", array[i]);
        }
        std::println("\n");

        // C++26 Modern Alternative 1: Print as a joined string using string_view
        // std::println("As a single string: {}", std::string_view(array, arraySize));
        // C++26 Modern Alternative 2: Print as a Python-style list range
        // std::println("As a debug range:   {:?}", std::string_view(array, arraySize));
    }

    void writeElements() {
    }

private:
    char* array = nullptr;  // Initialize to nullptr safely
    char* copiedArray = nullptr;
};


int main() {
    constexpr std::size_t CHAR_ARRAY_SIZE = 26;

    Buffer charArray = Buffer(CHAR_ARRAY_SIZE);

    charArray.readElements();

    // If the object is copied, a 'double deletion' would cause undefined behaviour
    // Buffer b2 = charArray;

    return 0;
}
