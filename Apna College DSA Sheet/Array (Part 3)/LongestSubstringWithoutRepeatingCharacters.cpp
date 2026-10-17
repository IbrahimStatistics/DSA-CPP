#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> maps;
        int ans = 0;
        int left = 0;

        for(int right=0; right<s.size(); right++) {
            if(maps.find(s[right]) != maps.end() && maps[s[right]]>=left) {
                left = maps[s[right]] + 1;
            }

            maps[s[right]] = right;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};


int main() {
    Solution sol;

    vector<pair<string, int>> tests = {
        {"", 0},
        {"a", 1},
        {"abcabcbb", 3},
        {"bbbbb", 1},
        {"pwwkew", 3},
        {"abcdef", 6},
        {"abba", 2},
        {"dvdf", 3},
        {"tmmzuxt", 5},
        {"aab", 2},
        {"abccdef", 4},
        {"anviaj", 5},
        {" ", 1},
        {"a b c", 3},
        {"1231234", 4},
        {"!@#$!%", 5}
    };

    int passed = 0;

    for (int i = 0; i < tests.size(); i++) {
        int actual = sol.lengthOfLongestSubstring(tests[i].first);
        int expected = tests[i].second;

        if (actual == expected) {
            cout << "Test " << i + 1 << ": PASS\n";
            passed++;
        } else {
            cout << "Test " << i + 1 << ": FAIL"
                 << " | Expected: " << expected
                 << " | Got: " << actual << '\n';
        }
    }

    cout << "\nPassed: " << passed
         << "/" << tests.size() << '\n';

    return 0;
}
