// # 4. Dynamically Allocate a Class Object
//
// Define a `Person` class with a name_ and age_. Dynamically allocate a single `Person` object, access its members through a pointer, and release the allocated memory.
//
// **Requirements:**
//
// - Read the name_ and age_ from standard input and validate the input before allocating the object.
// - Define a constructor that initializes the name_ and age_ and prints a construction message.
// - Define a destructor that prints a destruction message.
// - Use `new` to create the object and initialize it with the supplied values.
// - Define a member function that prints the person's details and call it through the pointer using `->`.
// - Use the matching `delete` to destroy the object and release its memory. Verify that the destructor's message appears.
// - Set the pointer to `nullptr` after deleting the object.
// - Explain the roles of the constructor and destructor, and what could happen if `delete` were omitted.

#include <print>
#include <memory>
#include <cstdint>

class Person {
private:
    std::string name_;
    int8_t age_;

public:
    Person(std::string person_name, int8_t person_age)
        : name_(person_name), age_(person_age) {  // Member initializer list
        std::println("Object 'Person' has been initialized.");
    }

    ~Person(){
        std::println("Object 'Person' has been destroyed.");
    }

    void personDetails() {
        std::println("Person's name_: {}", name_);
        std::println("Person's age_: {}", age_);
    }
};

int main() {

    return 0;
}
