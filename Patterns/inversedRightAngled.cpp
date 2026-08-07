#include<iostream>
using namespace std;

int main()
{
    // Inversed Right Angled Triangle
    
    int n;
    cout << "Enter n : ";
    cin >> n;
    
    cout << "Inversed Right Angled Triangle" << endl;
    for(int i = 0; i<n; i++)
    {
        for(int j = i; j<n; j++)
        {
            cout << "* ";
        }
            cout << '\n';
    }
    
    return 0;
}