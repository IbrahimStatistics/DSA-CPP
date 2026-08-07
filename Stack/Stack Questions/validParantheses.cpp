#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s[0] == ')' || s[0] == ']' || s[0] == '}') return false;

        int i = 0;
        stack<int> st;

        while(i<s.size()) {
            
            if(st.empty()) {
                st.push(s[i]);
            }

            
        }   

    }
};

int main() {

}