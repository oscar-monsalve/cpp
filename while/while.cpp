// Write a program that prompts the user to enter an integer in a while loop until "done" is entered. Print out to the user which number is
// larger and print the sum of the numbers.

#include <cctype>
#include <iostream>
#include <print>
#include <string>

int main() {

    int a;
    int b;
    int sum;
    std::string input;

    while (true) {
        std::print("Enter the first integer number (or \"done\" to finish): ");
        std::cin >> input;

        if (input == "done") {
            std::println("The program is finished");
            break;
        }

        // check if "a" is an integer
        if (!std::isdigit(static_cast<unsigned char>(input[0]))) {
            std::println("Error. Enter an integer");
            continue;
        }

        a = std::stoi(input);

        std::print("Enter the second integer number: ");
        std::cin >> b;

        if(a < b) {
            std::println("{} is less than {}", a, b);
        } else if (a == b) {
            std::println("{} is equal to {}", a, b);
        } else if (a > b){
            std::println("{} is greater than {}", a, b);
        }

    sum = a + b;
    std::println("The sum is {}", sum);

    }

    return 0;
}
