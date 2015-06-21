#include<iostream>
#include<string>

using namespace std;

// USING BOYER-MOORE'S algorithm with bad character heuristic
#define max(a,b) (a>b ? a : b)
#define SIZE 256

void badCharacterHeuristic(string pattern, int *arr){
	for(int i=0; i<pattern.length(); i++){
		arr[pattern[i]] = i;
	}
}

void findSubstring(string pattern, string input){
	if(pattern.length() > input.length()){
		return;
	}
	int *badArr = (int *)malloc(SIZE * sizeof(int));
	fill(badArr,badArr+SIZE,-1);
	badCharacterHeuristic(pattern,badArr);
	
	int m = pattern.length();
	int shift = 0;
	while(shift <= input.length() - m){
		int j=m-1;
		// compare backwards
		while(j>=0 && pattern[j] == input[shift+j]){
			j--;
		}
		// substring found
		if(j < 0){
			cout<<"Match occurs at index = "<<shift<<endl;
			// match the next character from input with last occurence in pattern
			//shift+m is the next character
			shift += (shift+m >= input.length()) ? 1 : m - badArr[input[shift+m]];
		}
		// substring not found
		else{
			// match the unmatched character with last occurence in pattern
			shift += max(1,j - badArr[input[shift+j]]);
		}
	}
}
/*
int main(){
	findSubstring("aabd","aabaabd");
	return 1;
}*/