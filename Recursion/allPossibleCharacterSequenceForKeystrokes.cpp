#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

void allPossibleCharacterSequenceForKeystrokes(map<char,string> keyMap, string current, string num){
	if(num.length() == 0){
		cout<<endl<<current;
		return;
	}
	while(num[0] == '0' || num[0] == '5'){
		num.erase(0,1);
	}
	string value = keyMap[num[0]];
	string current_copy = current;
	string num_copy = num;
	for(int i=0; i<value.length(); i++){
		current = current + value[i];
		num = num.erase(0,1);
		allPossibleCharacterSequenceForKeystrokes(keyMap,current,num);
		current = current_copy;//backtrack
		num = num_copy;//backtrack
	}
}