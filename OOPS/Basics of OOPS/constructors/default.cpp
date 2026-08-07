#include<iostream>
#include<string>
using namespace std;

class Teacher {
    private:
        double salary;
        int age;
    
    public:
        Teacher(string name, string dept, string subject) {
            cout << "Teacher's info:- " << endl;
            this->name = name;
            this->dept = dept;
            this->subject = subject;

        }

        string name;
        string dept;
        string subject;
};

int main() {
    Teacher t1("ABC","Computer Science","Computer Networks");
    // t1.name = "ABC";
    // t1.dept = "Computer Science";
    // t1.subject = "Data Structures";

    cout << "Name : " << t1.name << endl;
    cout << "Department : " << t1.dept << endl;
    cout << "Subject : " << t1.subject << endl;

    return 0;
}