#include<iostream>
#include<string>
using namespace std;

int main()
{
    int age;
    cout << "Age : "; 
    cin >> age;

    // char name[50];
    string name;
    getline(cin, name);

    cout << age << endl;
    // cout << name << endl;

    for(char ch : name)
    {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}