#include<iostream>

using namespace std;

int nthFibonacciNumber(int num){
	if(num <= 1){
		return num;
	}
	else{
		int fib1 = 0;
		int fib2 = 1;
		int sum = 0;
		for(int i=2; i<=num; i++){
			sum = fib1 + fib2;
			fib1 = fib2;
			fib2 = sum;
		}
		return fib2;
	}
}