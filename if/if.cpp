#include <iostream>
#include <print>

int main() {

    int a;
    int b;

    std::print("Enter a number: ");
    std::cin >> a;
    std::print("Enter other number: ");
    std::cin >> b;

    if (a<b) {
        std::println("{} is smaller than {}", a, b);
    } else if (a==b) {
        std::println("{} is equal to {}", a, b);
    } else {
        std::println("{} is not smaller than {}", a, b);
    }

    return 0;
}
