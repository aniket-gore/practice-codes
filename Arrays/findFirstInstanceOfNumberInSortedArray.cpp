#include<iostream>

using namespace std;

// The sorted array contains repeated numbers
// Time : O(log n)

void findFirstInstanceOfNumberInSortedArray(int *arr, int num, int low, int high){
	int mid = (low+high)/2;
	if(low == high || low + 1 == high){
		if(arr[low] == num){
			cout<<"Found at index : "<<low<<endl;
		}
		else if(arr[high] == num){
			cout<<"Found at index : "<<high<<endl;
		}
		else{
			cout<<"Not found. "<<endl;
		}
		return;
	}
	if(arr[mid] < num){
		findFirstInstanceOfNumberInSortedArray(arr,num,mid,high);
	}
	else{
		findFirstInstanceOfNumberInSortedArray(arr,num,low,mid);
	}
}
/*
int main(){
	int arr[] = {1,5,10,15,15,15,20,22,23,24,25};
	findFirstInstanceOfNumberInSortedArray(arr,15,0,10);
}*/