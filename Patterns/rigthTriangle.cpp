#include<iostream>
using namespace std;

int main()
{
    // Right Angled Triangle
    cout << "Right Angled Triangle" << endl;
    int n;
    
    cout << "Enter n : ";
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<=i; j++)
        {
            cout << "* ";
        }
            cout << '\n';
    }
    
    return 0;
}