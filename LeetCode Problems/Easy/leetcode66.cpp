#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    vector<int> arr = {1,2,3};
    int n = arr.size();
    vector<int> result;
    int digit = 0;
    
    for(int i = 0;i<arr.size() ;i++){
        arr[i]*= pow(10,n-1);
        n--;
        digit+=arr[i];
    }
    
    cout << "Next digit : " << ++digit;

    
    
    cout << digit << endl;
    
    for(int i : result) 
        cout << i << " ";
    
    return 0;
}
