#include<iostream>

using namespace std;

bool isValidCharacter(char ch){
	return (ch >= 'A' && ch<='Z') || (ch >= 'a' && ch <= 'z');
}

/*
Find if string is a palindrome.
Conditions: consider only letters, skip other characters.
			Ignore case of letters.
*/
bool findIfStringPalindrome(string str){
	if(str.length() <= 1){
		return true;
	}
	int start = 0, end = str.length()-1;
	while(start < end){
		if(!isValidCharacter(str[start])){
			start++;
		}
		else if(!isValidCharacter(str[end])){
			end--;
		}
		else if(str[start] == str[end] || abs(str[start]-str[end]) == abs('a'-'A')){
			start++;
			end--;
		}
		else{
			return false;
		}
	}
	return true;
}
/*
int main(){
	cout<<findIfStringPalindrome("A man, a plan, a canal -- Panama!")<<endl;
	return 1;
}*/