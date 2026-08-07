/*
Introduction to C and C++ Strings
*/

#include<iostream>
#include<typeinfo>
// #include<string>
// #include<cstring>
using namespace std;


int main()
{
    char name[50];
    cout << "Enter your name : ";

    // cin.getline(str, len, delimiter) | str => char array; len => No. of chars; delimiter =>
    cin.getline(name,100); // for C style string
    // getline(cin, name); // C++ style strings 

    cout << "Output : " << name << endl;
    
    return 0;
}


/*
int main()
{
    char str[] = {'a','b','c','\0'};
    char stringLiteral[] = "Hello";
    
    cout << str << endl;
    cout << typeid(str).name() << endl;
    // cout << strlen(str) << endl;
    cout << stringLiteral[5] << endl;
    

    // very bad method to input array
    char arr[10];
    cin >> arr ;
    cout << arr;

    return 0;
}
*/