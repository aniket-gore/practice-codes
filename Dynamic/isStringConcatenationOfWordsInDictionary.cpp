#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

/*
Given dictionary of words, check if given string is an arbirary contacatenation of words in dictinary.
e.g.
dictionary: "world", "hello", "super", "hell"
key: "helloworld" --> return true
key: "superman" --> return false
key: "hellohello" --> return true
*/

void displayOutput(vector<string> output){
	for(int i=0; i<output.size(); i++){
		cout<<output[i]<<endl;
	}
}

bool isStringConcatenationOfWordsInDictionary(string str, map<string,int> dict, vector<string> output){
	if(str.empty()){
		return true;
	}
	for(int size=1; size<=str.length(); size++){
		if(dict.find(str.substr(0,size)) != dict.end()){
			output.push_back(str.substr(0,size));
			// entire input string found, so display output
			if(str.length() == size){
				displayOutput(output);
				return true;
			}
			if(isStringConcatenationOfWordsInDictionary(&str[size],dict,output)){
				return true; 
			}
			output.pop_back();
		}
	}
	return false;
}

bool isStringConcatenationOfWordsInDictionaryMemoized(string str, map<string,int> dict, vector<string> output, map<string,int> &mem){
	if(str.empty()){
		return true;
	}

	if(mem.find(str) != mem.end()){
		return true;
	}

	for(int size=1; size<=str.length(); size++){
		if(dict.find(str.substr(0,size)) != dict.end()){
			mem.insert(make_pair(str.substr(0,size),1));
			output.push_back(str.substr(0,size));
			// entire input string found, so display output
			if(str.length() == size){
				return true;
			}
			if(isStringConcatenationOfWordsInDictionaryMemoized(&str[size],dict,output,mem)){
				return true; 
			}
			output.pop_back();
		}
	}
	return false;
}

bool isStringConcatenationOfWordsInDictionaryMemoizedCaller(string str, map<string,int> dict, vector<string> output){
	map<string,int> mem;
	return isStringConcatenationOfWordsInDictionaryMemoized(str,dict,output,mem);
}
/*
int main(){
	map<string,int> mp;
	mp.insert(make_pair("hello",1));
	mp.insert(make_pair("hell",1));
	mp.insert(make_pair("worn",1));
	mp.insert(make_pair("world",1));
	mp.insert(make_pair("w",1));
	mp.insert(make_pair("o",1));
	mp.insert(make_pair("wo",1));

	vector<string> output;
	cout<<isStringConcatenationOfWordsInDictionary("hellwornworn",mp,output)<<endl;
	cout<<isStringConcatenationOfWordsInDictionaryMemoizedCaller("hellowornworn",mp,output)<<endl;
	return 1;
}*/