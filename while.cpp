// Write a program that prompts the user to enter an integer in a while loop until "done" is entered. Print out to the user which number is
// larger and print the sum of the numbers.

#include<iostream>
#include <string>
using namespace std;

int main() {

    int a;
    int b;
    int sum;
    string input;

    while (true) {
        cout << "Enter the first integer number (or \"done\" to finish): ";
        cin >> input;

        if (input == "done") {
            cout << "The program is finished";
            break;
        }

        // check if "a" is an integer
        if (!isdigit(input[0])) {
            cout << "Error. Enter an integer" << endl;
            continue;
        }

        a = stoi(input);

        cout << "Enter the second integer number: ";
        cin >> b;

        if(a < b) {
            cout << a << " is less than " << b << endl;
        } else if (a == b) {
            cout << a << " is equal to " << b << endl;
        } else if (a > b){
            cout << a << " is greater than " << b << endl;
        }

    sum = a + b;
    cout << "The sum is " << sum << endl;

    }

    return 0;
}
