// ## 4. Dynamically Allocate a Single Object
//
// Dynamically allocate an integer, read its value from standard input, print it, and release the allocated memory.
//
// **Requirements:**
//
// - Use `new` and `delete`.
// - Set the pointer to `nullptr` after deleting the object.
// - Describe what could happen if the memory were not released.
//
// ----------------------------------------------------

/* Quick research on the topic:

   References: https://cplusplus.com/doc/tutorial/dynamic/

   In C++, 'new' and 'delete' are built-in language operators used to
   manage dynamic memory on the heap while automatically handling an
   object's lifecycle.

   The 'new' function allows to dynamically allocate memory for a single
   value or array of type <type>. The function 'new' returns a pointer to
   the beginning of the newly allocated memory.

   Characteristics:
   - Memory Allocation: It calculates the size of the type and requests
     that exact amount of bytes from the heap.

   - Initialization: It instantly runs the object's constructor to set up the data.

   - Failure Handling: If the system is out of memory, it throws a 'std::bad_alloc'
     exception (unless new(std::nothrow) is explicitly used, which returns nullptr):

     1. Throwing an exception:
     ```cpp
     foo = new int [5];  // if allocation fails, an exception is thrown
     ```

#include <iostream>
#include <new> // Required specifically to use the std::bad_alloc exception type

int main() {
    int* foo = nullptr;

    try {
        // Attempting dynamic memory allocation
        foo = new int[5];

        // Code that uses 'foo' goes here if allocation succeeds
        std::cout << "Memory allocated successfully.\n";

    }
    catch (const std::bad_alloc& e) {
        // This block executes ONLY if the system runs completely out of memory
        std::cerr << "Memory allocation failed: " << e.what() << "\n";

        // Take corrective action or gracefully terminate
        return 1;
    }

    // Clean up memory when done (only if foo was successfully allocated)
    delete[] foo;
    return 0;
}



     2. Checking for 'nullptr':
     The other method is known as 'nothrow'. When a memory allocation fails, instead
     of throwing a 'bad_alloc' exception or terminating the program, the pointer returned
     by 'new' is a null pointer, and the program continues its execution normally.
     This method can be specified by using a special object called 'nothrow', declared
     in the header <new>, as argument for new:

     ```cpp
     int * foo;
     foo = new (nothrow) int [5];
     if (foo == nullptr) {
       // error assigning memory. Take measures.
     }
     ```
     In this case, if the allocation of this block of memory fails, the failure can be
     detected by checking if foo is a null pointer


   'new' operator syntax:

   - Allocate memory to contain one single element of type <type>:
     ```cpp
     pointer = new type
     ```

   - Allocate a block (an array) of elements of type type, where 'number_of_elements'
     is an integer value representing the amount of these:
     ```cpp
     pointer = new type [number_of_elements]
     ```

   Example: allocate a block (an array) of 5 integers:
   ```cpp
   int * foo;
   foo = new type [number_of_elements];
   foo = new int [5];
   ```

   'delete' operator syntax:

   ```cpp
     // Syntax for a single object
     delete pointer;

     // Syntax for an array of objects
     delete[] array;
   ```

*/

#include <iostream>
#include <print>
#include <cassert>

// The library <new> is not necessary for basic usage of 'new' and 'delete'.
// However, it is necessary for 'new(std::nothrow) to return a 'nullptr'
// in the case of unsuccessful memory allocation.
#include <new>

int main () {
    int reqMemByUser;

    // Declaration of 'int pointer'.
    // It will point to te memory address of the first element of the
    // dynamically-allocated memery for the integer.
    int* ptr;

    std::println("Enter a positive integer to allocate memory for it: ");

    std::cin >> reqMemByUser;


    ptr = new int[reqMemByUser];

    std::println("Your input is: {}", reqMemByUser);

    return 0;
}
