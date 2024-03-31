#include<iostream>
#include<random>
#include<string>
#include<format>

using namespace std;

int main() {

    int guess_num;
    string input;


    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0,100);

    int randomNum = dis(gen);

    cout << "The random number is: " << randomNum << endl;


    while(true) {
        cout << "Guess a number: ";
        cin >> input;

        if (!isdigit(input[0])) {
            cout << "Invalid input" << "\n\n";
            continue;
        } 

        if (isdigit(input[0])) {
            guess_num = stoi(input);
            break;
        }

    }

    if (guess_num < randomNum) {
        cout << "The guessed number " << guess_num <<  " is less than the random number " << randomNum << "\n\n";
    } else if (guess_num > randomNum) {
        cout << "The guessed number " << guess_num <<  " is greater than the random number " << randomNum << "\n\n";
    } else if (guess_num == randomNum) {
        cout << "The guessed number " << guess_num <<  " is equal to the random number " << randomNum << "\n\n";
    }

    cout << "The program has finished succefully" << endl;

    return 0;
}