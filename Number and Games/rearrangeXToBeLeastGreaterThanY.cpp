#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

/*
From the set of natural integer numbers 
Let x = 1234 = {1, 2, 3, 4} 
Let y = 2410 = {2, 4, 1, 0} 

Write an algorithm to compute the rearrangement of x that is closest to y but still greater than y.
Both x and y have the same number of digits. 

So in the example above, the answer would be { 2, 4, 1, 3 } = 2413 which is greater than y = 2410 
and closer than any other arrangements of x. 

And whats the time complexity of this algorithm?
*/

//TODO---------------------------------------------------------------------------------
void rearrangeXToBeLeastGreaterThanY(int X[], int Y[], int length){
	if(X[length-1] < Y[0]){
		return;
	}
	int xindex=0, swapindex=1, yindex=0;

	while(xindex < length && swapindex <= length && yindex < length){
		if(X[xindex] == Y[yindex]){
			xindex++;
			yindex++;
		}
		else if(X[xindex] < Y[yindex]){
			swap(X[xindex],X[swapindex]);
			swapindex++;
		}
		else{
			break;
		}
	}
}

void rearrangeXToBeLeastGreaterThanYCaller(int X[], int Y[], int length){
	countSort(X,length,10);
	rearrangeXToBeLeastGreaterThanY(X,Y,length);
	for(int i=0; i<length; i++){
		cout<<X[i]<<",";
	}
	cout<<endl;
}