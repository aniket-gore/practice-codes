#include<iostream>

using namespace std;

// Time = O(lenA+lenB)
void mergeTwoSortedArrays(int arrA[], int lenA, int arrB[], int lenB){
	int *arr = (int *)malloc((lenA + lenB) * sizeof(int));
	int i=0, j=0, k=-1;
	while(i < lenA && j < lenB){
		if(arrA[i] < arrB[j]){
			arr[++k] = arrA[i++];
		}
		else{
			arr[++k] = arrB[j++];
		}
	}
	while(i < lenA){
		arr[++k] = arrA[i++];
	}
	while(j < lenB){
		arr[++k] = arrB[j++];
	}
	for(int index = 0; index<lenA+lenB; index++){
		cout<<arr[index]<<",";
	}
}