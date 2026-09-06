#include <print>
#include <random>

int main() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 100);

    int randomNum = dis(gen);

    std::println("The random number is: {}", randomNum);

    return 0;
}
