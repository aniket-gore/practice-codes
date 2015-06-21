#include<iostream>
#include<string>

using namespace std;
int count = 0;
void printAllWellOrderedStrings(int length, string str){
	if(length == 0){
		cout<<endl<<str;
		count++;
		cout<<"\t"<<count;
		return;
	}
	char last = str.length() > 0 ? str[str.length() - 1] : 0;
	if(last == 'z'){
		return;
	}
	else{
		if(str.length() == 0){
			last  = 'a' - 1;
		}
		for(char next = last + 1; next <= 'z'; next++){
			printAllWellOrderedStrings(length-1, str+next);
		}
	}
}