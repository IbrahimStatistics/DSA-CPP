#include<iostream>
#include<vector>
using namespace std;

void getAllSubsets(string& str, vector<char>& ans, int idx, vector<vector<string>>& subsets) {
    if(idx == str.size()) {
        subsets.push_back(ans);
        return;
    }

    // include
    ans.push_back(str[i]);
    getAllSubsets(str,ans,idx+1,subsets);

    ans.pop_back();
    //backtrack
    getAllSubsets(str,ans,idx+1,subsets);
}

int main() {
    string str = "abc";
    vector<string>ans;
    vector<vector<string>> subsets;

    getAllSubsets(str,ans,0,subsets);

    for(auto &i : subsets) {
        for(auto &j : i) {
            cout << j << " ";
        }
            cout << endl;
    }

    return 0;
}
