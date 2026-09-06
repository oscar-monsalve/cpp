#include <cmath>
#include <numbers>
#include <print>

int main() {

    double x = std::numbers::pi / 2;
    int y = 3;

    std::println("{}", std::sin(x));
    std::println("{}", std::pow(y, 2));

    return 0;

}
