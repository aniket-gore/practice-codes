#include<iostream>

using namespace std;

/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at 
both ends in the binary representation of N. 
E.g.:
The number 20 has binary representation 10100 and contains one binary gap of length 1. 
The number 15 has binary representation 1111 and has no binary gaps.
Write a function: class Solution { public int binary_gap(int N); } that, given a positive integer N, 
returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.
*/

int maxBinaryGap(int num){
	int max_gap = 0, curr_gap = 0;
	bool first_one_found_flag = false; // need to find the 1st one and then start counting zeroes. e.g.when num=8.

	while(num){
		if(num & 0x01){
			if(curr_gap > max_gap && first_one_found_flag){
				max_gap = curr_gap;
			}
			curr_gap = 0;
			first_one_found_flag = true;
		}
		else{
			curr_gap++;
		}
		num >>= 1;
	}
	return max_gap;
}
/*
int main(){
	cout<<"max_gap = "<<maxBinaryGap(82)<<endl;// 82 = 1010010
	return 1;
}*/