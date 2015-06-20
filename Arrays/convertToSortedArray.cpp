#include<iostream>

using namespace std;

/*
Given an array A of positive integers. Convert it to a sorted array with minimum cost. The only valid operation are: 
1) Decrement with cost = 1 
2) Delete an element completely from the array with cost = value of element
*/
//----------TODO--------------------------------------
int convertToSortedArray(int *arr, int length, int index){
	if(index == length-1){
		return 0;
	}
	int next_cost = convertToSortedArray(arr,length, index + 1);
	int dec = arr[index] - arr[index+1];
	dec = dec > 0 ? dec : 0;
	int decrement_cost = next_cost + dec;
	int delete_cost = next_cost + arr[index];

	if(delete_cost < decrement_cost){
		arr[index] = -1;
		return delete_cost;
	}
	arr[index] = decrement_cost;
	return decrement_cost;
}
/*
int main(){
	int arr[] = {10,2,3};
	cout<<endl<<"cost = "<<convertToSortedArray(arr,3,0)<<endl;
	return 0;
}*/