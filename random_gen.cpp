#include<iostream>
#include<random>

using namespace std;

int main() {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0,100);

    int randomNum = dis(gen);

    cout << "The random number is: " << randomNum << endl;

    return 0;
}