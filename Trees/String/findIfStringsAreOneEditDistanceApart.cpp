#include<iostream>
#include<string>

using namespace std;

/*
Find if 2 strings ar 1 edit distance apart (1 insert/delete/modify).
e.g.
-True
xyz,xz
xyz, xyk
xy, xyz


-False
xyz, xyz
xyz,xzy
x, xyz
*/
// Time : O(n) - length of larger string
bool findIfStringsAreOneEditDistanceApart(string str1, string str2){
	if(abs((int)(str1.length()-str2.length())) > 1){
		return false;
	}
	string shorter = str1.length() < str2.length() ? str1 : str2;
	string longer = str1.length() >= str2.length() ? str1 : str2;
	for(int i=0; i<shorter.length(); i++){
		// if mismatch found
		if(str1[i] != str2[i]){
			int offset = shorter.length() == longer.length() ? 0 : 1;
			shorter = shorter.substr(i+1);
			longer = longer.substr(i+1+offset);
			if(shorter == longer){
				return true;
			}
			return false;
		}
	}
	// if no mismatch
	return true;
}
/*
int main(){
	cout<<findIfStringsAreOneEditDistanceApart("cat","dog")<<endl;
	cout<<findIfStringsAreOneEditDistanceApart("cat","acts")<<endl;
	cout<<findIfStringsAreOneEditDistanceApart("cat","cats")<<endl;
	cout<<findIfStringsAreOneEditDistanceApart("cat","cut")<<endl;
	cout<<findIfStringsAreOneEditDistanceApart("cat","cast")<<endl;
	cout<<findIfStringsAreOneEditDistanceApart("cat","at")<<endl;
	return 1;
}*/