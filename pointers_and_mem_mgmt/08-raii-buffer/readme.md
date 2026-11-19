# 8. Implement an RAII Buffer

Create a `Buffer` class that owns a dynamically allocated character array.

**Requirements:**

- [x] Allocate the array in the constructor and release it in the destructor.
- [x] Implement or disable copying so that two objects never accidentally own the same allocation.
- [x] Provide safe methods for reading and writing elements.
- [x] Test the class with valid and invalid indices.
