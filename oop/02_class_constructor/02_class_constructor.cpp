#include <print>
#include <string>

// Constructor Rules:
// The constructor has the same name as the class.
// It has no return type (not even void).
// It is usually declared public.
// It is automatically called when an object is created.

class Employee {
    private:
        std::string name;
        float salary;

    public:
        // Constructor
        Employee(std::string employee_name, float employee_salary)
            : name(employee_name), salary(employee_salary) {}

        // Getters
        std::string get_name() {
            return name;
        }

        float get_salary() {
            return salary;
        }

        // Setters
        void set_name(std::string employee_name) {
            name = employee_name;
        }

        void set_salary(float employee_salary) {
            salary = employee_salary;
        }

        // Instance method
        void display_details() {
            std::println("Employee: {}, Salary: {}", name, salary);
        }

};

int main () {
    Employee employee_1("James", 2.0);
    Employee employee_2("Ana", 1.0);

    employee_1.display_details();
    employee_2.display_details();

    return 0;
}
