# 10. Model Shared and Weak Ownership

Create two classes, `Person` and `Team`. A team stores shared ownership of its members, while each person stores a non-owning reference back to the team.

**Requirements:**

- Use `std::shared_ptr` for team members.
- Use `std::weak_ptr` for the person's reference to the team.
- Print the relevant reference counts.
- Demonstrate that all objects are destroyed when the owning pointers leave scope.
- Explain how `std::weak_ptr` prevents a reference cycle.
