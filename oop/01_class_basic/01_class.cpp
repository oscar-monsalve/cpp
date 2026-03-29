#include<iostream>

class MyClass {
    public:
        void Method() {
            std::cout << "This is a class method\n";
    }

};

int main () {

    MyClass class_1;

    class_1.Method();

    return 0;
}
