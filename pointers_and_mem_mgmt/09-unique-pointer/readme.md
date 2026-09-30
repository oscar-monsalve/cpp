# 9. Transfer Ownership With `std::unique_ptr`

Create a `Resource` class that prints messages when it is constructed and destroyed. Manage it with `std::unique_ptr` and transfer ownership between functions.

**Requirements:**

- Create the resource with `std::make_unique`.
- Pass ownership using `std::move`.
- Show that the original pointer becomes empty after the transfer.
- Do not call `delete` manually.
