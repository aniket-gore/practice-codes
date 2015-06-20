#include<iostream>

using namespace std;

/*
Modify the array such that arr[I] = arr[arr[I]]. 
Do this in place i.e. with out using additional memory. 

example : if a = {2,3,1,0} 
o/p = a = {1,0,3,2} 

Note : The array contains 0 to n-1 integers.
*/
/*
	soln = multiply the answer by length, to get it later by dividing it by length.
			ALSO, add the original value to itself, so that it can be obtained later by mod length.
*/
void convertArrayToArrayOfArrayIndex(int arr[], int length){
	for(int i=0; i<length; i++){
		arr[i] =  arr[i] + (arr[arr[i] % length] % length) * length;
	}

	for(int i=0; i<length; i++){
		arr[i] /= length;
	}
}