// Pair sum optimal approach

#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> arr, int target);

int main(){
	vector<int> arr = {2,7,9,11,13,15};
	
	int target;
	cout << "Enter target value : ";
	cin >> target;

	vector<int> ans = pairSum(arr, target);

	for(int i : ans){
		cout << i << " ";
	}

	return 0;
}

vector<int> pairSum(vector<int> arr, int target){
	vector<int>ans;
	int i = 0, j = arr.size()-1;

	while(i<j){
		int pairSum = arr[i] + arr[j];

		if(pairSum > target){
			j--;
		} else if(pairSum < target){
			i++;
		} else{
			ans.push_back(i);
			ans.push_back(j);
			return ans;
		}
	}
	return ans;
}
