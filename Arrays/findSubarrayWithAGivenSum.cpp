#include<iostream>

using namespace std;

/*
If NEGATIVE integers in the array,
METHOD:
Suppose we have to find SUM in the array.
1) Go on adding cumulative sum into a map (key = sum, value = index)
2) While adding, if cumulative sum + SUM or cumulative sum - SUM is already in the map, we have found the answer.

Special case : If required SUM = 0,
Then, in step 2), we just need to find whether we have 2 same cumulative sums while adding into the map.
*/

// NOTE : Works only array for POSITIVE integers
void findSubarrayWithAGivenSum(int *arr, int length, int sum){
	int curr_sum = arr[0];
	int start = 0;
	for(int i=1; i<length; i++){
		while(curr_sum > sum && start < i-1){
			curr_sum -= arr[start];
			start++;
		}
		if(curr_sum == sum){
			cout<<endl<<"Subarray with sum = "<<sum<<" found at index = "<<start<<" to "<<i-1<<endl;
			return;
		}
		curr_sum += arr[i];
	}
	cout<<endl<<"Subarray not found."<<endl;
}