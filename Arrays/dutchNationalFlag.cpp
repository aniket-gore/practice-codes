#include<iostream>

using namespace std;

/*
Array contains 1,2 or 3. Sort the array with no memory in only 1 pass.
*/
// Time : O(n)
void dutchNationalFlag(int *arr, int len){
	int start = 0, end = len-1;
	
	for(int i=0; i<=end;){
		if(arr[i] < 2){
			swap(arr[start],arr[i]);
			start++;
			i++;
		}
		else if(arr[i] > 2){
			swap(arr[end],arr[i]);
			end--;
		}
		else{
			i++;
		}
	}
}
/*
int main(){
	int arr[] = {2,1,1,1,2,3,1,2,3,3,2,1,1,2,3,3,1,1,2,3};
	dutchNationalFlag(arr,20);
	for(int i=0; i<20; i++){
		cout<<arr[i]<<endl;
	}
	return 1;
}*/