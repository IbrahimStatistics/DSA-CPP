#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool anagram(string a, string b) {
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    if(a == b) return true;
    
    return false;
}

vector<string> removeAnagrams(vector<string>& words) {
    vector<string> result;
    for(int i = 1; i<words.size(); i++) {
        if(anagram(words[i],words[i-1])) {
            words.erase(words.begin()+i);
            result.push_back(words[i-1]);
        }
    }
    
    return result;
}

int main() {
    vector<string> words = {"abba","baba","baba","baba"};
    vector<string> result;
    result = removeAnagrams(words);
    
    for(auto i : result) {
        cout << i << " ";
    }
    
    return 0;
}