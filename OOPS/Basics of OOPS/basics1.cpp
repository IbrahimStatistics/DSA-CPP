#include<iostream>
#include<string>
using namespace std;

class Teacher {
    private:
    double salary;

    public:
    Teacher() {
        cout << "Hello, I am constructor class";
    }
    // properties or attributes
    string name;
    string dept;
    string subject;

    // methods or member functions
    void changeDept(string newDept) {
        dept = newDept;
    }
    
    // setter
    void setSalary(double s) {
        salary = s;
    }

    // getter
    double getSalary() {
        return salary;
    }
};


int main() {
    Teacher t1;
    t1.name = "John Doe";
    t1.subject = "C++";
    t1.dept = "Computer Science";
    t1.setSalary(25000);

    return 0;
}