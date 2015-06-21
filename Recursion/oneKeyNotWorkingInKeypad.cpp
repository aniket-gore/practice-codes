#include<iostream>

using namespace std;

bool oneKeyNotWorkingInKeypad(char entered[],int length1, char expected[], int length2){
	int i=0, badindex = 0;
	char badkey = NULL;

	if(length1 == 0){
		if(length2 < 2){
			return true;
		}
		int index=1;
		while(expected[index] != '\0'){
			if(expected[index] != expected[index-1]){
				return false;
			}
		}
	}

	while(expected[i] != '\0'){
		if(expected[i] != entered[badindex]){
			badkey = badkey==NULL ? expected[i] : badkey;
			if(expected[i] != badkey){
				return false;
			}
			badindex--;
		}
		i++;
		badindex++;
	}
	return true;
}