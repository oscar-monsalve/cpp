# C++ Pointers and Memory Management Exercises

## 1. Modify a Value Through a Pointer (DONE)

Write a program that declares an integer, stores its address in a pointer, and changes the integer's value through the pointer.

**Requirements:**

- Print the value and address before and after the modification.
- Explain the roles of the address-of (`&`) and dereference (`*`) operators.

## 2. Swap Two Values Using Pointers (DONE)

Implement a function `void swapValues(int* first, int* second)` that swaps two integers through pointers.

**Requirements:**

- Call the function from `main` and print the values before and after the swap.
- Handle null pointers without crashing.

## 3. Traverse an Array With Pointer Arithmetic (DONE)

Create an integer array and use only pointer arithmetic, rather than array indexing, to calculate its sum, minimum, and maximum values.

**Requirements:**

- Pass the beginning and end pointers to the calculation functions.
- Do not use expressions such as `array[index]` while traversing the array.

## 4. Dynamically Allocate a Single Object

Dynamically allocate an integer, read its value from standard input, print it, and release the allocated memory.

**Requirements:**

- Use `new` and `delete`.
- Set the pointer to `nullptr` after deleting the object.
- Describe what could happen if the memory were not released.

## 5. Build a Dynamic Array

Ask the user for an array size, dynamically allocate an array of that size, fill it with values, and calculate its average.

**Requirements:**

- Reject a size of zero or an unreasonably large size.
- Use `new[]` and the matching `delete[]`.
- Ensure all allocated memory is released on every exit path.

## 6. Deep Copy a Dynamic Array

Write a function `int* cloneArray(const int* source, std::size_t size)` that returns an independent copy of a dynamically allocated array.

**Requirements:**

- Return `nullptr` when the source pointer is null or the size is zero.
- Modify the copied array and demonstrate that the original is unchanged.
- Release both arrays correctly.

## 7. Fix Memory Management Bugs

Create a short program containing at least four memory errors, then identify and fix each one.

Include examples of:

- A memory leak.
- A dangling pointer.
- A double deletion.
- Mismatched `new[]` and `delete`.

Run the corrected program with AddressSanitizer or Valgrind and confirm that no memory errors remain.

## 8. Implement an RAII Buffer

Create a `Buffer` class that owns a dynamically allocated character array.

**Requirements:**

- Allocate the array in the constructor and release it in the destructor.
- Implement or disable copying so that two objects never accidentally own the same allocation.
- Provide safe methods for reading and writing elements.
- Test the class with valid and invalid indices.

## 9. Transfer Ownership With `std::unique_ptr`

Create a `Resource` class that prints messages when it is constructed and destroyed. Manage it with `std::unique_ptr` and transfer ownership between functions.

**Requirements:**

- Create the resource with `std::make_unique`.
- Pass ownership using `std::move`.
- Show that the original pointer becomes empty after the transfer.
- Do not call `delete` manually.

## 10. Model Shared and Weak Ownership

Create two classes, `Person` and `Team`. A team stores shared ownership of its members, while each person stores a non-owning reference back to the team.

**Requirements:**

- Use `std::shared_ptr` for team members.
- Use `std::weak_ptr` for the person's reference to the team.
- Print the relevant reference counts.
- Demonstrate that all objects are destroyed when the owning pointers leave scope.
- Explain how `std::weak_ptr` prevents a reference cycle.
