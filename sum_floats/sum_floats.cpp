#include <iostream>
#include <print>

int main() {

    double n1;
    double n2;
    double sum;

    std::println("Enter the first number:");
    std::cin >> n1;

    std::println("Enter the second number:");
    std::cin >> n2;

    sum = n1 + n2;

    std::println("The sum is {}", sum);

    return 0;

}
