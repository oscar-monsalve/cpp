#include <print>
#include <new>      // Provides 'std::nothrow'
#include <cstddef>  // Provides 'size_t'


class Buffer {
    char* array;
    const std::size_t arraySize;

public:
    Buffer(std::size_t arraySize)
        : arraySize(arraySize) {

        array = new (std::nothrow) char[arraySize];
        if (array == nullptr) {
            std::println("Allocation failed. Returning");
            return;
        }

        // Fill the array with the letters a to z
        for (std::size_t i = 'a'; i < 'z'; ++i) {
            array[i] = i;
        }
    }

    ~Buffer() {
        delete[] array;
        array = nullptr;
    }

    void printElements() {
        std::println("Array elements:");
        for (std::size_t i = 0; i < arraySize ; ++i) {
            std::println("{}", i);
        }
        std::println();
    }

private:
};


int main() {
    constexpr std::size_t CHAR_ARRAY_SIZE = 26;

    Buffer charArray = Buffer(CHAR_ARRAY_SIZE);


    charArray.printElements();

    return 0;
}
