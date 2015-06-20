#include<iostream>
#include<limits>

#define min(a,b) (a<b ? a : b)

using namespace std;

/*
Consider there is an array with duplicates and u r given two numbers as input and u have to return the 
minimum distance between the two in the array with minimum complexity.
*/
int minDistanceBetweenTwoElementsInRepeatedElementsArray(int arr[],int length, int num1, int num2){
	int min_distance, num1_index, num2_index;
	min_distance = num1_index = num2_index = INT_MAX;
	for(int i=0; i<length; i++){
		if(arr[i] == num1){
			num1_index = i;
		}
		if(arr[i] == num2){
			num2_index = i;
		}
		if(num1_index < INT_MAX && num2_index < INT_MAX){
			min_distance = min(min_distance,abs(num1_index - num2_index));
		}
	}
	return min_distance;
}