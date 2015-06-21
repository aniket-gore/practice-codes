#include<iostream>

using namespace std;

/*
OTHER WAY OF STATING THE PROBLEM:
We define C(n) as the number of ways to take n identical objects out of a bucket, 
where objects may be taken 1, 2, or 3 at a time. 
Example: C(4)=7, because you can take 4 objects in the following 7 ways: 
1,1,1,1 
2,1,1 
1,2,1 
1,1,2 
2,2 
3,1 
1,3

Write a function for C(n) in the language of your choice.
*/

int countWaysSteps(int n, int *mem){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	if(n == 2){
		return 2;
	}
	if(n == 3){
		return 4;
	}
	if(mem[n-1] != -1){
		return mem[n-1];
	}
	mem[n-1] = countWaysSteps(n-1,mem) + countWaysSteps(n-2,mem) + countWaysSteps(n-3,mem);
	return mem[n-1];
}

int countWaysStepsCaller(int n){
	int *mem = new int[n];
	fill(mem,mem+n,-1);
	return countWaysSteps(n,mem);
}