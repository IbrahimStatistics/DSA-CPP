// write a program to calculate exponentials without using any library

#include<iostream>
using namespace std;

int main()
{
    int n, index;
    cout << "Enter base and index : ";
    cin >> n >> index;

    int val = 1;

    for(int i = 1; i<=index; i++)
    {
        val *= n;
    }

    cout << val << endl;

    return 0;
}