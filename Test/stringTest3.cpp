#include<iostream>
#include<string>
using namespace std;

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

bool isPalindrome();

int main(){
    char ch;
    cout << "enter character : ";
    cin >> ch;
    
    bool result = isAlphanumericOrSpace(ch);
    
    if(result){
        cout << "Alphanumeric" << endl;
    } else{
        cout << "Special Symbol" << endl;
    }
    
    return 0;
}