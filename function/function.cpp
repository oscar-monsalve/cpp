#include <print>

int sum2(int x, int y) {
    return x + y;
}

int main() {

    int a = 5;
    int b = 6;

    std::println("The sum is {}", sum2(a, b));

    return 0;
}
