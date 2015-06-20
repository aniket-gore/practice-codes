#include<iostream>

using namespace std;

/*
Move all non-zero elements in the array to the left and return number of non-zero elements.
e.g.
Example input: [ 1, 0, 2, 0, 0, 3, 4 ]
output: 4
		array = [1, 4, 2, 3, 0, 0, 0]
Time : O(n)
Space : O(1)
*/

int moveAllNonZeroesToLeft(int *arr, int length){
	if(length == 0){
		return 0;
	}
	int nonzero_index = -1;
	// copy all non-zero elements to the start of the array
	for(int i=0; i<length; i++){
		if(arr[i] != 0){
			arr[++nonzero_index] = arr[i];
		}
	}
	// fill remaining array with zeroes
	int ret = length - nonzero_index;
	while(++nonzero_index < length){
		arr[nonzero_index] = 0;
	}
	return ret;
}
/*
int main(){
	int arr[] = {1, 0, 2, 0, 0, 3, 4};
	cout<<moveAllNonZeroesToLeft(arr,7)<<endl;
	for(int i=0; i<7; i++){
		cout<<arr[i]<<",";
	}
	cout<<endl;
	return 1;
}*/