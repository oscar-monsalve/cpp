#include<iostream>
using namespace std;

int main() {

    int a;
    int b;

    cout << "Enter a number: ";
    cin >> a;
    cout << "Enter other number:";
    cin >> b;

    if (a<b) {
        cout << a << " is smaller than " << b;
    } else if (a==b) {
        cout << a << " is equal to " << b;
    } else {
        cout << a << " is not smaller than " << b;
    }

    return 0;
}