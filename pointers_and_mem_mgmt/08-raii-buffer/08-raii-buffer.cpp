#include <print>
#include <new>          // Provides 'std::nothrow'
#include <cstddef>      // Provides 'std::size_t'
#include <string>       // Provides 'std::string'
#include <string_view>  // Provides 'std::string_view' for efficient name passing

// Additional behavious with respect to the exercise statement:
// Print dynamically the name of the class' object


class Buffer {
private:
    char* array = nullptr;  // Initialize to nullptr safely
    std::size_t arraySize;
    std::string name;

public:
    Buffer(std::size_t arraySize, std::string_view objectName)
        : arraySize(arraySize), name(objectName) {
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

    // Rule of three: 1. Copy constructor
    Buffer(const Buffer& other)
        : arraySize(other.arraySize), name(other.name) {
        array = new (std::nothrow) char[arraySize];
        if (array == nullptr) {
            std::println("Allocation failed. Returning");
            return;
        }

        for (std::size_t i = 0; i < arraySize; ++i) {
            array[i] = other.array[i];
        }
    }

    // Rule of three: 2. Copy-assignment operator
    Buffer& operator=(const Buffer& other) {
        // Handle assigning an object to itself: a = a
        if (this == &other) {
            return *this;
        }

        // Allocate independent storage before releasing our current storage.
        char* replacement = new char[other.arraySize];
        for (std::size_t i = 0; i < other.arraySize ; ++i) {
            replacement[i] = other.array[i];
        }

        // Replace the old allocation with the completed copy.
        delete[] array;
        array = replacement;
        arraySize = other.arraySize;
        name = other.name;

        return *this;
    }

    // Rule of three: 3. Destructor
    ~Buffer() {delete[] array;}

    // Getter to print the object's name
    std::string_view getName() const { return name; }

    void read() const {  // readElements() can be const, since it does not modify the buffer
        if (array == nullptr) return;

        std::println("Array elements for object '{}': ", name);
        for (std::size_t i = 0; i < arraySize ; ++i) {
            std::print("{} ", array[i]);
        }
        std::println("\n");

        // C++26 Modern Alternative 1: Print as a joined string using string_view
        // std::println("As a single string: {}", std::string_view(array, arraySize));
        // C++26 Modern Alternative 2: Print as a Python-style list range
        // std::println("As a debug range:   {:?}", std::string_view(array, arraySize));
    }

    void write(std::size_t index, char value) {
    }
};


int main() {
    constexpr std::size_t CHAR_ARRAY_SIZE = 26;

    std::println("Initialize first object 'b1':");
    Buffer b1(CHAR_ARRAY_SIZE, "b1");
    b1.read();

    std::println("Copy b1 to second object 'b2':");
    //
    Buffer b2 = b1;  // Triggers copy constructor
    b2.read();

    std::println("Initialize a third object 'b3' and rewrite its content from b1:");
    Buffer b3(5, "b3");
    b3.read();
    b3 = b1;  // Triggers copy-assignment operation
    b3.read();

    return 0;
}  // Destructors run in reverse construction order: b3, b2, then b1, each releasing its own allocation.
