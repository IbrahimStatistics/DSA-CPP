// Print all the possible permutations of a string
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getAllPermutations(string &str, vector<string> &result, int idx)
{
    if (idx == str.size())
    {
        result.push_back(str);
        return;
    }

    for (int i = idx; i < str.size(); i++)
    {
        swap(str[idx], str[i]);
        getAllPermutations(str, result, idx + 1);
        swap(str[idx], str[i]);
    }
}

int main()
{
    string str = "abc";
    vector<string> result;

    getAllPermutations(str, result, 0);

    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}