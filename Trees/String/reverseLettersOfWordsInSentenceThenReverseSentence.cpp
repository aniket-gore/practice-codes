#include<iostream>
#include<string>
#include<stack>

using namespace std;

/*
	Other problem : Reverse the order of words in a sentence
	Solution : Reverse the entire sentence. Then, reverse each word. Or vice-versa.
*/

string reverseLettersOfWords(string sentence){
	int next = 0;

	// skip leading spaces if any
	while(sentence[next] == ' '){
		next++;
	}
	while(next < sentence.length()){
		int start = next, end = next;
		// find 1st word
		next++;
		while(next < sentence.length() && sentence[next] != ' '){
			end++;
			next++;
		}
		// reverse the word
		while(start < end){
			swap(sentence[start],sentence[end]);
			start++;
			end--;
		}
		// skip the spaces
		while(next < sentence.length() && sentence[next] == ' '){
			next++;
		}
	}
	return sentence;
}

string reverseSentence(string reversed_words){
	stack<string> word_stack;
	int next = 0;
	// insert all words into stack
	while(next < reversed_words.length()){
		string word = "";
		while(next < reversed_words.length() && reversed_words[next] != ' '){
			word += reversed_words[next];
			next++;
		}
		word_stack.push(word);
		while(next < reversed_words.length() && reversed_words[next] == ' '){
			next++;
		}
	}
	// pop the stack and build the sentence
	string output = "";
	while(!word_stack.empty()){
		output += word_stack.top() + " ";
		word_stack.pop();
	}
	return output;
}

string reverseLettersOfWordsOfSentenceThenReverseSentence(string sentence){
	if(sentence.empty()){
		return NULL;
	}
	string reversed_words = reverseLettersOfWords(sentence);
	string reversed_sentence = reverseSentence(reversed_words);

	return reversed_sentence;
}

/*
int main(){
	string sente = "this is a mouse";
	cout<<reverseLettersOfWordsOfSentenceThenReverseSentence(sente)<<endl;
	return 1;
}*/