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

   A 'new' expression dynamically allocates an object or an array of objects.
   On success, it returns a pointer to the object or the first array element.

   Characteristics:
   - Memory Allocation: It requests storage for the object or array. The allocator
     may need additional space for bookkeeping or alignment.
   - Initialization: For class types, initialization can call a constructor.
     An 'int' has no constructor: 'new int' leaves its value uninitialized,
     'new int{}' initializes it to zero, and 'new int(value)' initializes it
     with 'value'. The stored value does not change the allocation size.

   'new' operator syntax:

   - Allocate memory to contain one single element of type <type>:
     ```cpp
      pointer = new type(value);
     ```

   - Allocate a block (an array) of elements of type type, where 'number_of_elements'
     is an integer value representing the amount of these:
     ```cpp
      pointer = new type[number_of_elements];
     ```

   Example: allocate a block (an array) of 5 integers:
   ```cpp
    int* foo = new int[5];
    // Use the array, then release it with delete[] foo.
   ```

   'delete' operator syntax:

   ```cpp
     // Syntax for a single object
     delete pointer;

     // Syntax for an array of objects
     delete[] array;
   ```

   - Failure Handling: Ordinary throwing allocation reports failure with
     'std::bad_alloc'. This can happen because of process limits or an inability
     to satisfy the request, not only because the entire system is out of memory.
     The 'std::nothrow' form returns nullptr on allocation failure instead.
     It does not suppress exceptions thrown by a class constructor.

     1. Throwing an exception:
       ```cpp
       foo = new int [5];  // if allocation fails, an exception is thrown
       ```

     Basic example with 'try' and 'catch' blocks:

     ```cpp
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
              // Handle an allocation request that could not be satisfied.
             std::cerr << "Memory allocation failed: " << e.what() << "\n";

             // Take corrective action or gracefully terminate
             return 1;
         }

          // Release the array. Deleting nullptr would also be safe.
         delete[] foo;
         return 0;
     }
     ```

     2. Checking for 'nullptr':
     The other method is known as 'nothrow'. When a memory allocation fails, instead
     of throwing a 'bad_alloc' exception or terminating the program, the pointer returned
     by 'new' is a null pointer, and the program continues its execution normally.
     This method can be specified by using a special object called 'nothrow', declared
     in the header <new>, as argument for new:

     ```cpp
     int * foo;
      foo = new (std::nothrow) int [5];
     if (foo == nullptr) {
        // Handle allocation failure before dereferencing foo.
     }
     ```
     In this case, if the allocation of this block of memory fails, the failure can be
      detected by checking if foo is a null pointer. Release a successfully
      allocated array with delete[] foo.
*/

#include <iostream>
#include <print>
#include <limits>

// The header <new> declares std::nothrow and std::bad_alloc.
// Basic new/delete expressions do not require this header.
#include <new>

int main () {
    int userValue = 0;

    std::println("Enter an integer to allocate memory on the heap to store it: ");

    // Extraction returns the stream; ! tests whether reading failed.
    if (!(std::cin >> userValue)) {
        std::println(
            "Error: enter an integer between {} and {}.",
            std::numeric_limits<int>::min(),
            std::numeric_limits<int>::max()
        );
        return 1;
    }

    // To simulate allocation failure, replace the allocation below with:
    // int* ptr = nullptr;
    // Allocate one int, initialized with userValue, not userValue integers.
    int *ptr = new (std::nothrow) int (userValue);

    // Check for allocation failure before dereferencing ptr.
    if (ptr == nullptr) {
        std::println("Error assigning memory. NUll pointer 'nullptr' found.");
        return 1;
    }

    std::println("Your input saved in the heap is: {}", *ptr);
    std::println("The memory was saved at the address: {}", static_cast<const void*>(ptr));

    // Release the single object allocated with new (not new[]).
    delete ptr;

    // Clear this dangling pointer; any other pointers to the object remain dangling.
    ptr = nullptr;

    return 0;
}


// A memory leak occurs when allocated memory is no longer reachable and has
// not been released. A local raw pointer going out of scope does not delete
// the object it points to. If no other pointer retains its address, the
// allocation remains occupied but cannot be accessed or released by the program.
// Example:

// ```cpp
// void memoryLeakExample() {
//     int *ptr = new int(10);  // Memory dynamically allocated
//     // Do something with the memory assigned.
//
//     // Forgot to delete the memory 'delete ptr'.
//
// }  // The pointer goes out of scope; the allocated integer remains allocated.
// ```
//
// Consequences:
// 1. The program loses access to memory that remains allocated.
// 2. Repeated leaks can increase memory usage over the lifetime of the process.
// 3. Memory pressure can cause slowdowns from paging, allocation failures,
// or termination by the operating system.
// The OS normally reclaims process memory on exit, but that does not prevent
// leaks from causing problems while the program is running.
