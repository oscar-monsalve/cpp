#include <print>
#include <new>          // Provides 'std::nothrow' and 'std::bad_alloc'
#include <cstddef>      // Provides 'std::size_t'
#include <string>       // Provides 'std::string'
#include <string_view>  // Provides 'std::string_view' for efficient name passing
#include <cstdio>       // Provides 'stderr'
#include <stdexcept>    // Provide 'std::out_of_range'

// Additional behavious with respect to the exercise statement:
// Print dynamically the name of the class' object


class Buffer {
private:
    char* array = nullptr;  // Initialize to nullptr safely
    std::size_t arraySize;
    std::string name = "unnamed";

public:
    Buffer(std::size_t arraySize,
           std::string_view objectName = "unnamed")
        : arraySize(arraySize), name(objectName) {
        array = new char[arraySize];  // Throws std::bad_alloc on failure.

        // Fill the array with the letters a to z
        for (std::size_t i = 0; i < arraySize; ++i) {
            array[i] = static_cast<char>('a' + i);
        }
    }

    // Rule of three: 1. Copy constructor
    Buffer(const Buffer& other)
        : arraySize(other.arraySize) {
        array = new char[arraySize];  // Throws std::bad_alloc on failure.

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

        return *this;
    }

    // Rule of three: 3. Destructor
    ~Buffer() {delete[] array;}

    // Setter to assign a name
    void setName(std::string_view objectName) {
        name = objectName;
    }

    void read() const {  // read() can be const, since it does not modify the buffer
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

    // Overloading 'read()' to support reading the buffer at an index
    char read(std::size_t index) const {
        if (index >= arraySize) {
            throw std::out_of_range("Buffer::read: index out of range.");
        }

        return array[index];
    }

    void write(std::size_t index, char value) {
        // Correct range for index is from 0 upto arraySize - 1
        if (index >= arraySize) {
            throw std::out_of_range("Buffer::write: index out of range.");
        }

        array[index] = value;
    }
};


int main() {
    constexpr std::size_t CHAR_ARRAY_SIZE = 26;

    // Throwing 'new' reports allocation failure with std::bad_alloc.
    // Let it propagate from constructors: failed construction produces no usable object.
    // When unwinding to catch, fully constructed local objects are destroyed automatically.
    try {
        std::println("Initialize first object 'b1':");
        Buffer b1(CHAR_ARRAY_SIZE, "b1");
        b1.read();

        std::println("Copy b1 to second object 'b2':");
        Buffer b2 = b1;  // Triggers copy constructor
        b2.setName("b2");
        b2.read();

        std::println("Initialize a third object 'b3' and rewrite its content from b1:");
        Buffer b3(5, "b3");
        b3.read();
        b3 = b1;  // Triggers copy-assignment operation
        b3.read();

        std::println("Writing elements to 'b1': ");
        b1.write(0, '1');
        b1.read();   // Read the whole object
        std::println("The first value of 'b1' after writing to it is: {}\n", b1.read(0));

        // Tests
        std::println("Tests: ");
        try {
            b1.read(CHAR_ARRAY_SIZE);  // Out of range for the read method
        }
        catch (const std::out_of_range& error) {
            std::println(stderr, "{}\n", error.what());
        }

        std::println("Verifying that copies are independent.");
        std::println("This checks that modifying the original doesn’t modify either copy:");
        std::println("b1: {}, b2: {}, b3: {}", b1.read(0), b2.read(0), b3.read(0));
    }

    catch (const std::bad_alloc& error) {
        std::println(stderr, "Memory allocation failed: {}", error.what());
        return 1;
    }

    return 0;
}  // Destructors run in reverse construction order: b3, b2, then b1, each releasing its own allocation.
