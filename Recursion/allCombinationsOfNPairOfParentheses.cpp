#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Time complexity : O(2^n)
void allCombinationsOfNPairOfParentheses(vector<string>	&list, int leftRem, int rightRem, string str){
	if(leftRem < 0 || rightRem < leftRem){
		return;
	}
	if(leftRem == 0 && rightRem == 0){
		list.push_back(str);
		return;
	}
	if(leftRem > 0){
		allCombinationsOfNPairOfParentheses(list,leftRem-1,rightRem,str+"(");
	}
	if(rightRem > leftRem){ // important
		str += ")";
		allCombinationsOfNPairOfParentheses(list,leftRem,rightRem-1,str);
	}
}