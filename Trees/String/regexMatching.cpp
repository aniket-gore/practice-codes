#include<iostream>
#include<string>

using namespace std;

// TODO for case: pat = "k*k", solution : validate the pattern at the start to convert "k*k" to "k*"
bool regexMatching(string text, string pattern){
	int text_i = 0, pat_j = 0;

	while(text_i < text.length()){
		// if text is longer than the pattern matched
		if(pat_j >= pattern.length()){
			return false;
		}
		if(text[text_i] == pattern[pat_j] || pattern[pat_j] == '.'){
			text_i++;
			pat_j++;
		}
		else if(pattern[pat_j] == '*'){
			char prev_ch = text[text_i - 1];
			while(text_i < text.length() && text[text_i] == prev_ch){
				text_i++;
			}
			pat_j++;
		}
		else{
			return false;
		}
	}
	return true;
}

/*
int main(){
	cout<<regexMatching("Facebookkkkka","F.cebo*k*a")<<endl;
	return 1;
}*/