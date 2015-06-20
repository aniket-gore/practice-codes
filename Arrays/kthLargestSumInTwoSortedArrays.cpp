#include<iostream>
#include<queue>
#include<vector>

#define max2(a,b) (a>b ? a : b)
using namespace std;

//TODO for arrays of different lengths------------------------------------------------------------
int kthLargestSumInTwoSortedArrays(int *a, int *b, int lena, int lenb, int k){
	priority_queue<int,vector<int>,greater<int>> min_heap;

	int aindex=lena-1, bindex=lenb-1;
	//push the largest sum on heap
	min_heap.push(a[aindex]+b[bindex]);
	aindex--;
	bindex--;
	while(aindex > 0 && bindex > 0){
		for(int i=lena-1; i>=aindex; i--){
			int newsum = a[i]+b[bindex];
			if(min_heap.size() < k){
				min_heap.push(newsum);	
			}
			else{
				if(min_heap.top() < newsum){
					min_heap.pop();
					min_heap.push(newsum);
				}
			}
		}
		for(int i=lenb-1; i>=bindex; i--){
			int newsum = a[aindex]+b[i];
			if(min_heap.size() < k){
				min_heap.push(newsum);	
			}
			else{
				if(min_heap.top() < newsum){
					min_heap.pop();
					min_heap.push(newsum);
				}
			}
		}
		aindex--;
		bindex--;
	}
	return min_heap.top();
}