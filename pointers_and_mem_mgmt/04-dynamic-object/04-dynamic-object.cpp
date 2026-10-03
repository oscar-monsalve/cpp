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

#include <iostream>
#include <print>
#include <string>
#include <new>

class Person {
private:
    std::string name_;
    unsigned int age_;

public:
    Person(std::string person_name, unsigned int person_age)
        : name_(person_name), age_(person_age) {  // Member initializer list
        std::println("Object 'Person' has been initialized.");
    }

    ~Person(){
        std::println("Object 'Person' has been destroyed.");
    }

    void personDetails() {
        std::println("Person's name: {}", name_);
        std::println("Person's age: {}", age_);
    }
};

int main() {
    std::string name{};
    unsigned int age{};

    std::println("Enter your name: ");
    if (!(std::cin >> name)) {
        std::println("Error: enter a valid name.");
        return 1;
    }

    std::println("Enter your age: ");
    if (!(std::cin >> age)) {
        std::println("Error: enter a valid age.");
        return 1;
    }

    Person* person1 = new (std::nothrow) Person(name, age);
    if (person1 == nullptr) {
        std::println("Error assigning memory. Null pointer 'nullptr' found.");
        return 1;
    }
    person1->personDetails();
    delete person1;
    person1 = nullptr;

    return 0;
}
