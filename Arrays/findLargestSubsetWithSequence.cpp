#include<iostream>
#include<map>

using namespace std;

/*
Given an int array which might contain duplicates, find the largest subset of it which form a sequence. 
Eg. {1,6,10,5,7,9,4} 
then ans is 4,5,6,7 

Sorting is an obvious solution. Can this be done in O(n) time
*/
void findLargestSubsetWithSequence(int arr[], int length){
	map<int,int> indexMap;
	int sequence_start=0, sequence_end=0;//final sequence start and end values
	for(int i=0; i<length; i++){
		int start = arr[i], end = arr[i];
		//ignore if number has already occurred once
		if(indexMap.find(arr[i]) != indexMap.end()){
			continue;
		}
		indexMap[arr[i]] = arr[i];
		int value_minus_1 = arr[i] - 1;
		int value_plus_1 = arr[i] + 1;
	
		if(indexMap.find(value_minus_1) != indexMap.end()){
			start = indexMap[value_minus_1];
			//reset the map values because now we are going to update the start value
			if(indexMap[value_minus_1] != value_minus_1){
				swap(indexMap[value_minus_1],indexMap[indexMap[value_minus_1]]);
			}
		}
		if(indexMap.find(value_plus_1) != indexMap.end()){
			end = indexMap[value_plus_1];
			//reset the map values because now we are going to update the end value
			if(indexMap[value_plus_1] != value_plus_1){
				swap(indexMap[value_plus_1],indexMap[indexMap[value_plus_1]]);
			}
		}

		//swap the map values to maintain correct start,end indices
		swap(indexMap[start],indexMap[end]);

		if(sequence_end - sequence_start <= end - start){
			sequence_end = end;
			sequence_start = start;
		}
	}
	cout<<sequence_start<<" - "<<sequence_end<<endl;
}
