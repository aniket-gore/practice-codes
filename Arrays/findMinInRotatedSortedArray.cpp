#include<iostream>

using namespace std;

//// [-11, -5, 2, 7, 13]
//// [2, 7, 13, -11, -5]
//// [13, -11, -5, 2, 7]
// Time : O(log n)
int findMinInRotatedSortedArray(int *arr, int n){
	int low = 0, high = n-1, mid;
	
	while(low <= high){
		if(arr[low] < arr[high]){
			return low;
		}
		mid = (low + high)/2;
		if(mid+1 < n && arr[mid] > arr[mid+1]){
			return mid+1;
		}
		if(mid-1 >=0 && arr[mid] < arr[mid-1]){
			return mid;
		}
		if(arr[low] > arr[mid]){
			high = mid;
		}
		else{
			low = mid;
		}
	}
}
/*
int main(){
	int arr[] = {1,3,5,7,9,-5,-3};
	cout<<findMinInRotatedSortedArray(arr,7)<<endl;
	return 1;
}*/