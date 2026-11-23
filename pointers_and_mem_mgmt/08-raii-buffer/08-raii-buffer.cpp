#include <print>
#include <new>          // Provides 'std::nothrow' and 'std::bad_alloc'
#include <cstddef>      // Provides 'std::size_t'
#include <string>       // Provides 'std::string'
#include <string_view>  // Provides 'std::string_view' for efficient name passing
#include <cstdio>       // Provides 'stderr'
#include <stdexcept>    // Provides 'std::out_of_range'

// Additional behavious with respect to the exercise statement:
// Print dynamically the name of the class' object


class Buffer {
private:
    char* array = nullptr;  // Initialize to nullptr safely
    std::size_t arraySize;
    std::string name = "unnamed";

public:
    Buffer(std::size_t arraySize, std::string_view objectName = "unnamed")
        : arraySize(arraySize), name(objectName) {
        array = new char[arraySize];  // Throws std::bad_alloc on failure.

        // Fill with successive character codes starting at 'a', converted to char.
        // On ASCII-compatible systems, values beyond 'z' continue into punctuation.
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

    void printElements() const {  // Printing does not modify the buffer.
        std::println("Array elements for object '{}': ", name);
        for (std::size_t i = 0; i < arraySize ; ++i) {
            std::print("{} ", array[i]);
        }
        std::println("\n");

        // C++23 alternative: print the characters as a string using string_view.
        // std::println("As a single string: {}", std::string_view(array, arraySize));
        // C++23 alternative: print a quoted string with special characters escaped.
        // std::println("As a debug string: {:?}", std::string_view(array, arraySize));
    }

    // Read a single character, rejecting indices outside the buffer.
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
        b1.printElements();

        std::println("Copy b1 to second object 'b2':");
        Buffer b2 = b1;  // Triggers copy constructor
        b2.setName("b2");
        b2.printElements();

        std::println("Initialize a third object 'b3' and rewrite its content from b1:");
        Buffer b3(5, "b3");
        b3.printElements();
        b3 = b1;  // Triggers copy-assignment operation
        b3.printElements();

        std::println("Writing elements to 'b1': ");
        b1.write(0, '1');
        b1.printElements();   // Print all elements.
        std::println("The first value of 'b1' after writing to it is: {}\n", b1.read(0));

        // Tests
        std::println("============");
        std::println("Tests: ");
        std::println("============");

        // 1. Read/write index 0: expected success
        try {
            std::println("1. Read at first index for b3: {}", b3.read(0));
            b3.write(0, 'Z');
            std::println("Write at first index for b3: {}\n", b3.read(0));
        }
        catch (const std::out_of_range& error) {
            std::println(stderr, "{}\n", error.what());
        }

        // 2. Read/write index 'size - 1': expected success
        try {
            std::println("2. Read at last index for b3: {}", b3.read(CHAR_ARRAY_SIZE - 1));
            b3.write(CHAR_ARRAY_SIZE - 1, 'A');
            std::println("Write at last index for b3: {}\n", b3.read(CHAR_ARRAY_SIZE - 1));
        }
        catch (const std::out_of_range& error) {
            std::println(stderr, "{}\n", error.what());
        }

        // 3. Read at index 'size': expected exception
        std::println("3. Read out-of-bounds for b3:");
        try {
            std::println("3. Read out-of-bounds for b3: {}", b3.read(CHAR_ARRAY_SIZE));
        }
        catch (const std::out_of_range& error) {
            std::println(stderr, "{}\n", error.what());
        }

        // 4. Write at index 'size': expected exception
        std::println("4. Write out-of-bounds for b3:");
        try {
            b3.write(CHAR_ARRAY_SIZE, 'G');
        }
        catch (const std::out_of_range& error) {
            std::println(stderr, "{}", error.what());
        }
        std::println("b3 contents unchanged since last change: ");
        b3.printElements();

        // 5. Zero-sized buffer, index 0: expected exception
        std::println("5. Zero-sized buffer, index 0, trying to read:");
        try {
            Buffer zeroSizedBuffer(0, "zeroSizedBuffer");
            zeroSizedBuffer.read(0);
        }
        catch (const std::out_of_range& error) {
            std::println(stderr, "{}", error.what());
        }
        std::println("   Zero-sized buffer, index 0, trying to write:");
        try {
            Buffer zeroSizedBuffer(0, "zeroSizedBuffer");
            zeroSizedBuffer.write(0, 'X');
        }
        catch (const std::out_of_range& error) {
            std::println(stderr, "{}\n", error.what());
        }

        // 6. Self-assigment: expected contents unchanged
        std::println("6. Self-assigment (expected unchanged contents): ");
        try {
            Buffer obj1(2, "obj1");
            obj1.printElements();
            obj1 = obj1;
            obj1.printElements();
        }
        catch (const std::out_of_range& error) {
            std::println(stderr, "{}", error.what());
        }

        // 7. Modify a copy: expected original unchanged
        std::println("7. Modify a copy (expected original unchanged): ");
        try {
            Buffer original(30, "original");
            original.printElements();

            Buffer copy = original;
            copy.setName("copy");
            copy.printElements();

            copy.write(0, 'Z');

            original.printElements();
            copy.printElements();

        }
        catch (const std::out_of_range& error) {
            std::println(stderr, "{}", error.what());
        }

        std::println("Verifying that copies are independent.");
        std::println("This checks that modifying the original doesn’t modify either copy:");
        std::println("b1: {}, b2: {}, b3: {}", b1.read(0), b2.read(0), b3.read(0));
    } // b3, b2, then b1 are destroyed here; nested-scope buffers were destroyed earlier.

    catch (const std::bad_alloc& error) {
        std::println(stderr, "Memory allocation failed: {}", error.what());
        return 1;
    }

    return 0;
}
