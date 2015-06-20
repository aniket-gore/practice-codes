#include<iostream>

using namespace std;

int rotatedArrayFindElement(int arr[], int start, int end, int element){
	int mid = (start + end) / 2;
	if(element == arr[mid]){
		return mid;
	}
	if(arr[mid] > arr[start]){// there is no rotation
		if(element < arr[mid]){
			return rotatedArrayFindElement(arr,start,mid-1,element);
		}
		else{
			return rotatedArrayFindElement(arr,mid+1,end,element);
		}
	}
	else{ // there is rotation
		if(element < arr[mid]){
			return rotatedArrayFindElement(arr,start,mid-1,element);
		}
		else if(element <= arr[end]){// = is important to consider the last element in the array
			return rotatedArrayFindElement(arr,mid+1,end,element);
		}
		else{
			return rotatedArrayFindElement(arr,start,mid-1,element);
		}
	}
}