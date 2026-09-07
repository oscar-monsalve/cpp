#include <cctype>
#include <iostream>
#include <print>
#include <random>
#include <string>

int main() {

    int guess_num;
    std::string input;


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 100);

    int randomNum = dis(gen);

    std::println("The random number is: {}", randomNum);


    while(true) {
        std::print("Guess a number: ");
        std::cin >> input;

        if (!std::isdigit(static_cast<unsigned char>(input[0]))) {
            std::println("Invalid input\n");
            continue;
        }

        if (std::isdigit(static_cast<unsigned char>(input[0]))) {
            guess_num = std::stoi(input);
            break;
        }

    }

    if (guess_num < randomNum) {
        std::println("The guessed number {} is less than the random number {}\n", guess_num, randomNum);
    } else if (guess_num > randomNum) {
        std::println("The guessed number {} is greater than the random number {}\n", guess_num, randomNum);
    } else if (guess_num == randomNum) {
        std::println("The guessed number {} is equal to the random number {}\n", guess_num, randomNum);
    }

    std::println("The program has finished successfully");

    return 0;
}
