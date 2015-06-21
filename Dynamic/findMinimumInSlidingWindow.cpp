#include<iostream>

using namespace std;
#define min(a,b) (a<b ? a : b)

/*
Example: [2,1,3,4,6,3,8,9,10,12,56] w=4 
1. partition the array in blocks of size w=4. The last block may have less then w. 
2, 1, 3, 4 | 6, 3, 8, 9 | 10, 12, 56| 
2. Traverse the list from start to end and calculate min_so_far. Reset min to 0 after each block (of w elements). 
min_so_far[] = 2, 1, 1, 1 | 6, 3, 3, 3 | 10, 10, 10 
3. Similarly calculate min_in_future by traversing from end to start. 
min_in_future[] = 1, 1, 3, 4 | 3, 3, 8, 9 | 10, 12, 56 
4. now, min at each position i in current window, sliding_min(i) = min {min_in_future[i], min_so_far[i+w-1]} 
sliding_min = 1, 1, 3, 3, 3, 3, 8, ....
*/
void findMinimumInSlidingWindow(int arr[], int length, int w_size){
	int *min_so_far = new int[length];
	fill(min_so_far,min_so_far+length,-1);
	min_so_far[0] = arr[0];

	int *min_in_future = new int[length];
	fill(min_in_future,min_in_future+length,-1);
	min_in_future[0] = arr[length-1];

	for(int i=1; i<length; i++){
		min_so_far[i] = (i%w_size == 0) ? arr[i] : min(arr[i-1],arr[i]);
	}
	for(int i=length-2; i>=0; i--){
		min_in_future[i] = (i%w_size == w_size-1) ? arr[i] : min(arr[i],arr[i+1]);
	}

	int *min_in_sliding_window = new int[length-w_size+1];
	for(int i=0; i<length-w_size+1; i++){
		min_in_sliding_window[i] = min(min_in_future[i],min_so_far[i+w_size-1]);
		cout<<min_in_sliding_window[i]<<",";
	}
}
