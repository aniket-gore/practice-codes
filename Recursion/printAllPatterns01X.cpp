#include<iostream>

using namespace std;

/*
Input string = "0110?11?0?1". Find all possible strings where ? can be 0 or 1.
*/
void printAllPatterns01X(char *str, int index){
	if(index == strlen(str)){
		cout<<endl<<str;
		return;
	}
	if(str[index] == '0' || str[index] == '1'){
		printAllPatterns01X(str,index+1);
	}
	if(str[index] == '?'){
		str[index] = '0';
		printAllPatterns01X(str,index+1);
		str[index] = '1';
		printAllPatterns01X(str,index+1);
		str[index] = '?';
	}
}