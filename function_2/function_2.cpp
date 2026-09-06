#include <print>

int multiply(int x, int y) {
    return x * y;
}


int main() {

    int a = 5;
    int b = 5;

    std::println("The multiplication is {}", multiply(a, b));

    return 0;
}
