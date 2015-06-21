#include<iostream>

using namespace std;

/*
Given a series of numbers as the input, the last one as the result.
Use the rest numbers to calculate the result,only +, -, *, / are allowed.
The order of the input cannot be changed. If there is an equation, print it; or print "no equation".
If more than one solution, any working equation is fine. 

example: 
input: 2, 3, 1, 4 
output: 2+3-1 = 4.
*/
double getResult(int a, int b, char op){
	switch(op){
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
}

// op = list of operators
bool fitIntoEquation(double *arr, int start, int end, double result, char *op){
	if(start == end){
		if(arr[start] == result){
			return true;
		}
		else{
			return false;
		}
	}
	for(int i=0; i<4; i++){
		double temp = arr[start+1];
		arr[start+1] = getResult(arr[start],temp,op[i]);
		if(fitIntoEquation(arr,start+1,end,result,op)){
			arr[start+1] = temp;
			cout<<endl<<arr[start]<<op[i]<<arr[start+1];
			return true;
		}
		arr[start+1] = temp;
	}
	return false;
}
