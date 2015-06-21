#include<iostream>

using namespace std;

void printString(char *str, int i, int j){
	cout<<endl;
	for(int index = i; index <= j; index++){
		cout<<str[index];
	}
}

void longestPalindromeSubstring(char *str){
	int length = strlen(str);
	bool  **table = new bool *[length];
	for(int i=0; i<length; i++){
		table[i] = new bool[length]();
	}
	
	//for len = 1
	for(int i=0; i<length; i++){
		table[i][i] = true;
	}
	
	int start_index = -1, max_length = 1;
	
	//for len = 2
	for(int i=0; i<length-1; i++){
		if(str[i] == str[i+1]){
			table[i][i+1] = true;
			start_index  = i;
			max_length = 2;
			printString(str,i,i+1);
		}
	}

	//for len > 2
	for(int k=3; k<=length; k++){//length of substring
		for(int i=0; i<length-k+1; ++i){//starting index of substring
			int j  = i+k-1;//ending index of substring
			if(table[i+1][j-1] && str[i] == str[j]){
				table[i][j] = true;
				if(k > max_length){
					start_index = i;
					max_length = k;
				}
				printString(str,i,j);
			}
		}
	}
	cout<<endl<<"Maxsubstring starting index = "<<start_index<<"\tof length = "<<max_length<<endl;
}