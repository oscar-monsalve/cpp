# 4. Dynamically Allocate a Class Object

Define a `Person` class with a name and age. Dynamically allocate a single `Person` object, access its members through a pointer, and release the allocated memory.

**Requirements:**

- Read the name and age from standard input and validate the input before allocating the object.
- Define a constructor that initializes the name and age and prints a construction message.
- Define a destructor that prints a destruction message.
- Use `new` to create the object and initialize it with the supplied values.
- Define a member function that prints the person's details and call it through the pointer using `->`.
- Use the matching `delete` to destroy the object and release its memory. Verify that the destructor's message appears.
- Set the pointer to `nullptr` after deleting the object.
- Explain the roles of the constructor and destructor, and what could happen if `delete` were omitted.
