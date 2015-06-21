#include<iostream>

using namespace std;

/*
1. ch = 'a', shift = 1, output = 'b'
2. ch = 'z', shift = 2, output = 'b'
*/
char characterShift(char character, int shift){
	// logic: find character - 'a' then add shift
	return 'a' + (character - 'a' + shift) % 26;
}
/*
int main(){
	char ch = 'a';
	cout<<characterShift(ch,2)<<endl;
	return 1;
}*/