#include<iostream>

using namespace std;

/*
Given a sequence of numbers such that A[i] >= A[i+1] and A[N-1] >= A[N-2] find at-least one triplet such that 
A[n-1] >= A[n] <= A[n+1]. Better than linear time is expected.
Example: 9 8 5 4 3 2 6 7
Answer: 3 2 6
*/

void findLocalMinima(int *arr, int n){
	int low = 0, high = n-1, mid;
	int count = 0;
	while(low < high - 1){
		cout<<++count<<endl;
		mid = (low + high)/2;
		if(arr[mid-1] >= arr[mid] && arr[mid] <= arr[mid+1]){
			cout<<"Triplet = "<<arr[mid-1]<<","<<arr[mid]<<","<<arr[mid+1]<<endl;
			return;
		}
		if(arr[mid-1] >= arr[mid] && arr[mid] > arr[mid+1]){
			low = mid;
		}
		else{
			high = mid;
		}
	}
	cout<<"No local minima"<<endl;
}

void findLocalMinimaRecursive(int *arr, int low, int high){
	if(low >= high-1){
		cout<<"No minima"<<endl;
		return;
	}
	int mid = (low + high)/2;
	if(arr[mid-1] >= arr[mid] && arr[mid] <= arr[mid+1]){
		cout<<"Triplet = "<<arr[mid-1]<<","<<arr[mid]<<","<<arr[mid+1]<<endl;
		return;
	}
	if(arr[mid-1] >= arr[mid] && arr[mid] > arr[mid+1]){
		findLocalMinimaRecursive(arr,mid,high);
	}
	else{
		findLocalMinimaRecursive(arr,low,mid);
	}
}
/*
int main(){
	int arr[] = {50,30,20,15,12,10,8,7,6,3,10,12};
	//findLocalMinima(arr,12);
	findLocalMinimaRecursive(arr,0,11);
	return 1;
}*/