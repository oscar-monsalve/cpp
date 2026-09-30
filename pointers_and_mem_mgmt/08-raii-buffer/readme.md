# 8. Implement an RAII Buffer

Create a `Buffer` class that owns a dynamically allocated character array.

**Requirements:**

- Allocate the array in the constructor and release it in the destructor.
- Implement or disable copying so that two objects never accidentally own the same allocation.
- Provide safe methods for reading and writing elements.
- Test the class with valid and invalid indices.
