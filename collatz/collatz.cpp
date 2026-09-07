 // Take any positive integer n. If n is even, divide n by 2 to get n / 2. If n is odd, multiply n by 3 and add 1
 // to get 3n + 1. Repeat the process indefinitely. The conjecture states that no matter which number you start
 // with, you will always reach 1 eventually. Given a number n, return the number of steps required to reach 1.

#include <cctype>
#include <iostream>
#include <print>
#include <string>

int main() {

    int n;
    int count = 0;
    std::string input;

    while  (true){
        std::print("Enter an integer: ");
        std::cin >> input;

        if (!std::isdigit(static_cast<unsigned char>(input[0]))) {
            std::println("Invalid input.\n");
        }

        if (std::isdigit(static_cast<unsigned char>(input[0]))) {
            n = std::stoi(input);
            break;
        }

    }

    while (true) {

        if (n == 1) {
            std::println("The program has reached: {}\n", n);
            break;
        } else if (n % 2 == 0) {
            n = n / 2;
        } else if (n % 2 != 0) {
            n = 3*n + 1;
        }

        count++;

        std::println("{}", n);

    }

    std::println("It took {} cycles to reach {}", count, n);

    return 0;
}
