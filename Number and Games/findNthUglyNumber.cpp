#include<iostream>

using namespace std;
#define min(a,b,c) (a<b ? (a<c ? a : c) : (c<b ? c : b))

//Ugly number is a number whose prime factors are only 2,3 or 5
int findNthUglyNumber(int n){
	int *arr = new int[n];
	fill(arr,arr+n,-1);
	int index2 = 0, index3 = 0, index5 = 0;
	int next_multiple_of_2 = 2, next_multiple_of_3 = 3, next_multiple_of_5 = 5;
	arr[0] = 1;

	for(int i=1; i<n; i++){
		int nextnumber = min(next_multiple_of_2,next_multiple_of_3,next_multiple_of_5);
		arr[i] = nextnumber;
		if(nextnumber == next_multiple_of_2){
			index2++;
			next_multiple_of_2 = arr[index2] * 2;
		}
		if(nextnumber == next_multiple_of_3){
			index3++;
			next_multiple_of_3 = arr[index3] * 3;
		}
		if(nextnumber == next_multiple_of_5){
			index5++;
			next_multiple_of_5 = arr[index5] * 5;
		}
	}
	return arr[n-1];
}