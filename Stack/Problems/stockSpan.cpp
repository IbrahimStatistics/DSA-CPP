#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    //stock prices
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    //solution
    vector<int> ans(price.size(), 0);
    stack<int> s;

    for(int i = 0; i<price.size(); i++) {
        while(s.size() > 0 && price[s.top()] <= price[i]) {
            s.pop();
        }
        
        if(s.empty()) {
            ans[i] = i+1;
        } else {
            ans[i] = i - s.top(); // i - prevHigh
        }

        s.push(i);
    }

    for(auto i : ans) cout << i << " ";

    return 0;
}