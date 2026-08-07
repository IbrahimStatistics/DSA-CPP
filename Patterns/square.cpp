#include<iostream>
using namespace std;

// n = 5

int main()
{
    // Square pattern
    cout << "Square Pattern" << endl;
    int sides = 5;
    for(int i = 0; i<sides; i++)
    {
        for(int j = 0; j<sides; j++)
        {
            cout << "* ";
        }
            cout << '\n';
    }
    
    cout << endl << endl;
    
    
    
    // // Right Angled Triangle
    // cout << "Right Angled Triangle" << endl;
    // int n = 5;
    // for(int i = 0; i<n; i++)
    // {
    //     for(int j = 0; j<=i; j++)
    //     {
    //         cout << "* ";
    //     }
    //         cout << '\n';
    // }
    
    // cout << endl << endl;

    
    // // Inversed Right Angled Triangle
    // cout << "Inversed Right Angled Triangle" << endl;
    // for(int i = 0; i<n; i++)
    // {
    //     for(int j = i; j<n; j++)
    //     {
    //         cout << "* ";
    //     }
    //         cout << '\n';
    // }
    
    // cout << endl << endl;
    
    // // Equilateral Triangle
    
    // cout << "Equilateral Triangle" << endl;
    // for(int i = 0; i<n; i++)
    // {
    //     for(int j = 0; j<n-(i+1); j++)
    //     {
    //         cout << " ";
    //     }
    //     for(int k = 0; k<=i; k++)
    //     {
    //         cout << "* ";
    //     }
        
    //         cout << '\n';
    // }
    
    // cout << endl << endl;
    
    
    return 0;
}