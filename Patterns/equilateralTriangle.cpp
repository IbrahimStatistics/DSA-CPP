#include<iostream>
using namespace std;

int main()
{
    // Equilateral Triangle
    
    int n;
    cout << "Enter n : ";
    cin >> n;
    
    cout << "Equilateral Triangle" << endl;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n-(i+1); j++)
        {
            cout << " ";
        }
        for(int k = 0; k<=i; k++)
        {
            cout << "* ";
        }
        
            cout << '\n';
    }
    
    cout << endl << endl;
    
    
    return 0;
}