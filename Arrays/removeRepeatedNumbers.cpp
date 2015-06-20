#include<iostream>

using namespace std;
// remove consecutive repeated characters
int removeRepeatedNumbers(int arr[], int length){
	int i=0, j;
	while(i<length){
		j = i;
		while(arr[i] == arr[j]){
			j++;
		}
		// if no repetition
		if(j-i == 1){
			i++;
			continue;
		}
		//if repetition
		int k=0;
		// copy rest of the characters before repetition
		while(j+k < length){
			arr[i+k] = arr[j+k];
			k++;
		}
		// update length of array
		length = length - (j-i);
		if(i-1 >= 0){
			i--;
		}
	}
	return length;
}
