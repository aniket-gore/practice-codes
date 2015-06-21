#include<iostream>
#include<string>

using namespace std;

void printPermutationOfNumberNoRepetition(string number, string digits, int rem_length){
	if(rem_length == 0){
		cout<<endl<<number;
		return;
	}
	for(int i=0; i<digits.length(); i++){
		string number_copy = number;// needed while backtracking
		number += digits[i];
		string digits_copy = digits;// needed while backtracking
		digits.erase(i,1);
		printPermutationOfNumberNoRepetition(number, digits,rem_length-1);
		number = number_copy;
		digits = digits_copy;
	}
}