#include<iostream>

using namespace std;

/*
Find the majority number in a given sequence of numbers (a number that occurs more than N/2 times where N is the count of numbers in the sequence). Don't maintain a map of all occurring numbers along with a count. No number may be a majority. 

Example: 1 1 2 3 4 1 6 1 7 1 1 
Majority number is 1 since it occurs 6 times (> 11/2)
*/
void findMajorityNumber(int arr[], int length){
	int count = 1, num = arr[0];
	for(int i=1; i<length; i++){
		if(arr[i] == num){
			count++;
		}
		else if(count == 0){
			count = 1;
			num = arr[i];
		}
		else{
			count--;
		}
	}
	count = 0;
	for(int i=0; i<length; i++){
		if(arr[i] == num){
			count++;
		}
	}
	if(count * 2 > length){
		cout<<endl<<"Majority number = "<<num<<endl;
	}
	else{
		cout<<endl<<"No majority number"<<endl;
	}
}