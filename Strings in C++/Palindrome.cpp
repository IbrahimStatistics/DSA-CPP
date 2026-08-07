// Check if the given string is a palindrome or not
// example - racecar, madam, radar, LOL etc..

#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>

using namespace std;

bool isPalindrome(string str);

bool isPalindrome(string str){

    int start = 0, end = str.length()-1;
    while(start<=end){
        if(tolower(str[start]) != tolower(str[end])){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main(){
    string str = "1&2";

    bool result = isPalindrome(str);
    
    if(result){
        cout << "String is Palindrome";
    } else{
        cout << "String is not a Palindrome";
    }

    return 0;
}