#include<iostream>

using namespace std;

//keep in mind the range values
void countSort(int *arr, int length, int range){
	int *counts = (int *)malloc((range+1) * sizeof(int));
	fill(counts,counts+range+1,0);

	for(int i=0; i<length; i++){
		counts[arr[i]]++;
	}

	for(int i=0,j=0; i<range+1; i++){
		while(counts[i]--){
			arr[j++] = i;
		}
	}
}