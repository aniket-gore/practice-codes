#include<iostream>

using namespace std;

// Each digit should be greater than previous digit
static int count = 0;
void generateAllNDigitNumbers(int length, int number){
	if(length == 0){
		cout<<endl<<number<<"\t"<<++count;
		return;
	}
	int last = number%10;
	if(last == 9){
		return;
	}
	if(number == 0){
		last = 0;
	}
	for(int i=last+1; i<=9; i++){
		number = number * 10 + i;
		generateAllNDigitNumbers(length-1, number);
		number = number/10;	//backtrack
	}
}