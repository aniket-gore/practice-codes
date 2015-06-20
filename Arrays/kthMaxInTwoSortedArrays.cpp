#include<iostream>

using namespace std;

// Time = O(log k)
// Shorten that array(by kBy2) which has kBy2 th element greater than the other array
// Arrays are descending in order
int kthMaxInTwoSortedArrays(int *arrA, int lenA, int *arrB, int lenB, int k){
	int kBy2 = k/2;
	if(k == 0){
		return -1;
	}
	if(k == 1){
		if(lenA > 0 && lenB > 0){
			return arrA[0] > arrB[0] ? arrA[0] : arrB[0];
		}
		else if(lenA > 0){
			return arrA[0];
		}
		else if(lenB > 0){
			return arrB[0];
		}
		else{
			return -1;
		}
	}
	if(lenA > 0 && lenB > 0){
		if(arrA[kBy2-1] < arrB[kBy2-1]){
			return kthMaxInTwoSortedArrays(arrA,lenA,&arrB[kBy2],lenB-kBy2,k-kBy2);
		}
		return kthMaxInTwoSortedArrays(&arrA[kBy2],lenA-kBy2,arrB,lenB,k-kBy2);
	}
	if(lenA > 0){
		return kthMaxInTwoSortedArrays(&arrA[kBy2],lenA-kBy2,arrB,lenB,k-kBy2);
	}
	if(lenB > 0){
		return kthMaxInTwoSortedArrays(arrA,lenA,&arrB[kBy2],lenB-kBy2,k-kBy2);
	}
	return -1;
}
/*
int main(){
	int arrA[] = {50,40,38,35,20,10,5,3,2,1};
	int arrB[] = {60,52,44,39,32,12,11,8,7,4};
	cout<<"kth largest = "<<kthMaxInTwoSortedArrays(arrA,10,arrB,10,14)<<endl;
	return 1;
}*/