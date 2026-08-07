#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {1,2,2,3,3,2,1,1};
    int n = arr.size();
    int count = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            count = 0;
            if(arr[i]==arr[j]){
                count++;
            } else {
                continue;
            }
        }

        cout << count;
    }

    return 0;
}