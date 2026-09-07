#include <print>

class MyClass {
    public:
        void Method() {
            std::println("This is a class method");
    }

};

int main () {

    MyClass class_1;

    class_1.Method();

    return 0;
}
