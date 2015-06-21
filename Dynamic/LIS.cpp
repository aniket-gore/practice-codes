#include<iostream>

using namespace std;

//Longest increasing subsequence
//LIS[i] = max(LIS(j)+1), j=0 to i-1, j<i, arr[j]<arr[i]
int LIS_recursive(int *arr, int high){
	if(high == 0){
		return 1;
	}
	int curr_max = 0;
	int curr;
	for(int i=0; i<high; i++){
		curr = LIS_recursive(arr,i);
		if(arr[i] < arr[high] && curr > curr_max){
			curr_max = curr;
		}
	}
	return curr_max+1;
}

int LIS_TDM(int *arr, int high, int *mem){
	if(high == 0){
		return 1;
	}
	if(mem[high] != 0){
		return mem[high];
	}
	int curr_max = 0;
	int curr;
	for(int i=0; i<high; i++){
		mem[i] = LIS_recursive(arr,i);
		curr = mem[i];
		if(arr[i] < arr[high] && curr > curr_max){
			curr_max = curr;
		}
	}
	return curr_max+1;
}

int LIS_TDMCaller(int *arr, int length){
	int *mem = (int *)malloc(length * sizeof(int));
	fill(mem,mem+length,0);
	return LIS_TDM(arr,length-1,mem);
}