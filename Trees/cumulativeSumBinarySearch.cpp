#include<iostream>

using namespace std;

//Used when retrieving an item with probability already specified
int cumulativeSumBinarySearch(double prob[], int start, int end, double randomNum){
	if(start == end){
		return start;
	}
	int mid = (start+end)/2;	
	if(randomNum <= prob[mid] && randomNum > prob[mid-1]){
		return mid;
	}
	if(randomNum < prob[mid]){
		return cumulativeSumBinarySearch(prob,start,mid-1,randomNum);
	}
	else{
		return cumulativeSumBinarySearch(prob,mid+1,end,randomNum);
	}
}