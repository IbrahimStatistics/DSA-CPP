// Reversing a string

// i). Reversing a character array... C Style string.

/*
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<char> str = {'H','e','l','l','o'};

    int start = 0, end = str.size()-1;

    while(start<end){
        swap(str[start++],str[end--]);
    }

    for(char letters:str){
        cout << letters << " ";
    }

    return 0;
}
*/

// ii). Reversing a string 

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string name = "Ibrahim";
    reverse(name.begin(),name.end());  // Iterators

    cout << name;

    return 0;
}