#include<iostream>

using namespace std;

#define max(a,b) (a>b ? a : b)

/*
Sort the array. You are allowed to do only following operation on array.

flip(arr, i): Reverse array from 0 to i . Assume this operation is done in O(1).

Methods:
1) Time : O(n^2) -> For all elements find max and flip to the end of array.
2) Time : O(nlogn) -> Go on traversing the array, do insertion sort (find correct position by binary search) and flip.
*/

void flip(int *arr, int i){
	int start = 0;
	while(i > start){
		swap(arr[start],arr[i]);
		start++;
		i--;
	}
}

// O(n^2)
void pancakeSort(int *arr, int n){
	int max_index;
	for(int i=n-1; i>=0; i--){
		// find max
		max_index = 0;
		for(int j=0; j<=i; j++){
			if(arr[max_index] < arr[j]){
				max_index = j;
			}
		}
		// flip it to the end of array
		if(max_index != i){
			flip(arr,max_index);
			flip(arr,i);
		}
	}
}

int findIndex(int *arr, int low, int high, int element){
	if(element <= arr[low]){
		return low;
	}
	if(element > arr[high]){
		return -1;
	}
	int mid = (low + high)/2;
	if(element == arr[mid]){
		return mid;
	}
	if(element < arr[mid]){
		return findIndex(arr,low,mid,element);
	}
	else{
		return findIndex(arr,mid+1,high,element);
	}
}

// O(nlogn)
void pancakeSortBinarySearch(int *arr, int n){
	for(int i=1; i<n; i++){
		// find correct index in insertion sort
		int j = findIndex(arr,0,i-1,arr[i]);
		if(j != -1){
			flip(arr,j-1);
			flip(arr,i-1);
			flip(arr,i);
			flip(arr,j);
		}
	}
}
/*
int main(){
	int arr[] = {2,10,3,6,4,9,8,7,1,5};
	//pancakeSort(arr,10);
	pancakeSortBinarySearch(arr,10);
	for(int i=0; i<10; i++){
		cout<<arr[i]<<",";
	}
	cout<<endl;
	return 1;
}*/