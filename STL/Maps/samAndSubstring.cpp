#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'substrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING n as parameter.
 */
void getAllSubstring(string n) {
    if(i == limit) {
        ans+=(int)substring;
    }

    temp_substring = n.substr(1,i);
    getAllSubstring(n);

    temp_substring.pop_back();
}


int substrings(string n) {

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
