#include<iostream>
#include<string>

using namespace std;

void printAllPermutationsOfString(string str, int start, int end){
	if(start == end){
		cout<<endl<<str;
		return;
	}
	for(int i=start; i<=end; i++){
		swap(str[start],str[i]);
		printAllPermutationsOfString(str,start+1,end);
		swap(str[start],str[i]);
	}
}