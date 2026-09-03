// The for-each for loop is used to loop within an array

#include<iostream>
using namespace std;

int main() {    

    int arr[] = {1, 2, 3, 4, 5};

    for (int i : arr) {

        cout << i << endl;
    }

    return 0;

}
