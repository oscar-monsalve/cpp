#include <print>

int main() {

    int array[] = {5, 3, 6, 10};

    for (int value : array) {
        std::println("{}", value);
    }

    return 0;
}
