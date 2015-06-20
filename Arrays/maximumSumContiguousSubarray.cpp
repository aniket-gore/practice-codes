#include<iostream>

#define max(a,b) (a>b ? a : b)

int maximumSumContiguousSubarray(int arr[], int length){
	int max=0, curr_max=0;
	for(int i=0; i<length; i++){
		curr_max += arr[i];
		if(curr_max < 0){
			curr_max = 0;
		}
		if(max < curr_max){
			max = curr_max;
		}
	}
	return max;
}


// This handles the case of array containing all negatives.

int maxSubArraySum(int a[], int size)
{
    int max_so_far = a[0], i;
    int curr_max = a[0];
           
    for (i = 1; i < size; i++){
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}
