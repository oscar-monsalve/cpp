 // Take any positive integer n. If n is even, divide n by 2 to get n / 2. If n is odd, multiply n by 3 and add 1 to get 3n + 1. Repeat
 // the process indefinitely. The conjecture states that no matter which number you start with, you will always reach 1 eventually. Given
 // a number n, return the number of steps required to reach 1.

#include<iostream>
#include<string>

using namespace std;

int main() {

    int n;
    int count = 0;
    string input;

    while  (true){
        cout << "Enter an integer: ";
        cin >> input;

        if (!isdigit(input[0])) {
            cout << "Invalid input." << "\n\n";
        }

        if (isdigit(input[0])) {
            n = stoi(input);
            break;
        }

    }

    while (true) {

        if (n == 1) {
            cout << "The program has reached: " << n << "\n\n";
            break;
        } else if (n % 2 == 0) {
            n = n / 2;
        } else if (n % 2 != 0) {
            n = 3*n + 1;
        }

        count++;

        cout << n << endl;

    }

    cout << "It took " << count << " cycles to reach " << n << endl;

    return 0;
}
