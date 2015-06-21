#include<iostream>
#include<string>

using namespace std;

void findAllSubstrings(string str){
	if(str.length() == 0){
		return;
	}
	int count = 0;
	for(int i=0; i<str.length(); i++){
		for(int size=1; size<=str.length()-i; size++){
			cout<<endl<<str.substr(i,size);
			count++;
		}
	}
	cout<<endl<<count;
}
/*
int main(){
	findAllSubstrings("string");
	cout<<endl;
	return 1;
}
*/