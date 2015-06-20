#include<iostream>

using namespace std;

/*
Given an array where every element occurs three times, except one element which occurs only once. 
Find the element that occurs once. 
Expected time complexity is O(n) and O(1) extra space.

Solution:
Count bits in all positions. Mod each position count by number of repetitions. You get the answer.
e.g. 
Let us consider the example array {5, 5, 5, 8}. The 101, 101, 101, 1000
Sum of first bits%3 = (1 + 1 + 1 + 0)%3 = 0;
Sum of second bits%3 = (0 + 0 + 0 + 0)%3 = 0;
Sum of third bits%3 = (1 + 1 + 1 + 0)%3 = 0;
Sum of fourth bits%3 = (1)%3 = 1;
Hence number which appears once is 1000
*/

int findElementOccursOnce(int *arr, int length){
	int element = 0, bit, sum = 0;

	for(int i=0; i<32; i++){// INT SIZE = 32
		bit = 1 << i;
		sum = 0;
		for(int index=0;  index<length; index++){
			if(arr[index] & bit){
				sum++;
			}
		}
		if(sum % 3){
			element = element | bit;
		}
	}
	return element;
}
/*
int main(){
	int arr[] = {5,5,5,2,2,2,4,4,4,10,6,6,6,7,7,7};
	//int arr[] = {5,5,2,2,4,4,10,6,6,7,7};
	cout<<findElementOccursOnce(arr,16)<<endl;
	return 1;
}*/