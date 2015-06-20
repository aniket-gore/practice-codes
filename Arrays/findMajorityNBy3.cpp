#include<iostream>

using namespace std;

/*
Design an algorithm that, given a list of n elements in an array, finds all the elements that appear more than n/3 times 
in the list. The algorithm should run in linear time ( n >=0 ) 

You are expected to use comparisons and achieve linear time. 
No hashing/excessive space/ and don't use standard linear time deterministic selection algo
*/
void findMajorityNBy3(int arr[], int length){
	int count[2] = {0}, num[2] = {-1};
	for(int i=0; i<length; i++){
		if(arr[i] == num[0]){
			count[0]++;
		}
		else if(arr[i] == num[1]){
			count[1]++;
		}
		else if(count[0] == 0){
			count[0] = 1;
			num[0] = arr[i];
		}
		else if(count[1] == 0){
			count[1] = 1;
			num[1] = arr[i];
		}
		else{
			count[0]--;
			count[1]--;
		}
	}
	count[0] = count[1] = 0;
	for(int i=0; i<length; i++){
		if(arr[i] == num[0]){
			count[0]++;
		}
		if(arr[i] == num[1]){
			count[1]++;
		}
	}
	bool flag = false;
	if(count[0] * 3 > length){
		cout<<endl<<"Majority number = "<<num[0]<<endl;
		flag = true;
	}
	if(count[1] * 3 > length){
		cout<<endl<<"Majority number = "<<num[1]<<endl;
		flag = true;
	}
	if(!flag){
		cout<<endl<<"No majority number"<<endl;
	}
}