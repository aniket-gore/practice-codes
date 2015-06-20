#include<iostream>

using namespace std;

/*
Given an integer, print the next smallest and next largest number that have 
the same number of 1 bits in their binary representation.
*/

// index starts from zero
int getBit(int num, int index){
	return num & (1 << index);
}

int setBit(int num, int index, bool value){
	if(value){
		return num | (1 << index);
	}
	else{
		return num & ~(1 << index);
	}
}

int immediateGreaterNumberWithSameNumberOf1s(int num){
	if(num <= 0){
		return -1;
	}

	int index = 0, count_ones = 0;
	//find first 1
	while(!getBit(num,index)){
		index++;
	}
	// then find first 0
	while(getBit(num,index)){
		index++;
		count_ones++;
	}
	// set this 0 to 1
	num = setBit(num,index,true);
	count_ones--;
	// set previous 1 to 0
	index--;
	num = setBit(num,index,false);

	// set all original number of 0s 
	for(int i=--index; i>=count_ones; i--){
		num = setBit(num,i, false);
	}

	// set all original number of 1s
	for(int i=count_ones-1; i>=0; i--){
		num = setBit(num,i, true);
	}
	return num;
}

int immediateSmallerNumberWithSameNumberOf1s(int num){
	if(num <= 0){
		return -1;
	}

	int index = 0, count_ones = 0;
	//find first 0
	while(getBit(num,index)){
		index++;
	}
	// then find first 1
	while(!getBit(num,index)){
		index++;
		count_ones++;
	}
	// set this 1 to 0
	num = setBit(num,index,false);
	count_ones--;
	// set previous 0 to 1
	index--;
	num = setBit(num,index,true);

	// set all original number of 1s 
	for(int i=--index; i>=count_ones; i--){
		num = setBit(num,i, true);
	}

	// set all original number of 0s
	for(int i=count_ones-1; i>=0; i--){
		num = setBit(num,i, false);
	}
	return num;
}