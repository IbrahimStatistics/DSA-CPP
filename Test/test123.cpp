#include<iostream>
#include<typeinfo>
using namespace std;

int main() {
    int x;
    int* ptr = nullptr;
    cout << typeid(x).name() << endl;
    cout << typeid(nullptr).name() << endl;
}