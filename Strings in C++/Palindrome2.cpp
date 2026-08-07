#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrom(string str);
bool isAlphanumericOrSpace(char ch);

bool isAlphanumericOrSpace(char ch) {
    int ascii = (int)ch;  // Get ASCII value

    if ((ascii >= 48 && ascii <= 57) ||   // 0-9
        (ascii >= 65 && ascii <= 90) ||   // A-Z
        (ascii >= 97 && ascii <= 122) ||  // a-z
        (ascii == 32)) {                  // space
        return true;
    }
    return false;
}

bool isPalindrom(string str) {
    int start = 0,end = str.length()-1;

    while(start<=end) {
    if (!isAlphanumericOrSpace(str[start])) {
        start++;
        continue;
    }
    if (!isAlphanumericOrSpace(str[end])) {
        end--;
        continue;
    }

    if(tolower(str[start++]) == tolower(str[end--])) 
        continue;
    else 
        return false;
 
    }

    return true;
}

int main() {
    string random = "Ac3?e3c&a";
    // string random = "hello";

    bool result = isPalindrom(random);

    if(result)
        cout << "String is Palindrome";
    else   
        cout << "String is not Palindrome";

    return 0;
}