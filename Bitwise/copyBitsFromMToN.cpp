#include<iostream>

using namespace std;

/*
You are given two 32-bit numbers, N and M, and two bit positions, i and j.
Write a method to set all bits between i and j in N equal to M 
(e.g., M becomes a substring of N located at i and starting at j).
EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6
Output: N = 10000101010
*/
void copyBitsFromMToN(int N, int M, int i, int j){
	int temp = ~0;
	int left = temp - ((1 << j) - 1);//put all 1s from left till j-1
	int right = (1 << (i-1)) - 1;//put all 1s from right till i+1
	int output = left | right;//combine
	output = (N & output) | (M << (i-1));
	cout<<endl<<"copy bits from M to N = "<<output<<endl;
}