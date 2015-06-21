#include<iostream>

using namespace std;
//order of denominations in the array is not important, they can be random eg. {10,1,25,5}
int allPossibleWaysOfMakeChange(int amount, int denomination[], int length, int index){
	int count = 0;
	if(amount < 0){
		return 0;
	}
	if(amount == 0){
		return 1;
	}
	for(int i=index; i<length; i++){
		count = count + allPossibleWaysOfMakeChange(amount - denomination[i],denomination,length,i);
	}
	return count;
}