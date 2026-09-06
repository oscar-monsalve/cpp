#include <iostream>
#include <print>

int main() {

    int n1;
    int n2;
    int sum;

    std::print("Enter the first number: ");
    std::cin >> n1;
    std::print("Enter the second number: ");
    std::cin >> n2;

    sum = n1+n2;

    std::println("The sum is: {}", sum);

    return 0;

}
