/*
LEETCODE 121 - BEST TIME TO BUY AND SELL STOCKS
*/

#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices);

int maxProfit(vector<int>& prices){
    int maxProfit = INT64_MIN;
    int minPrice = INT64_MAX;

    for(int price : prices){
        
    }

    return maxProfit;
}

int main(){
    vector<int> profit = {7,1,5,3,6,4};
    cout << "Max Profit : " << maxProfit(profit);

    return 0;
}