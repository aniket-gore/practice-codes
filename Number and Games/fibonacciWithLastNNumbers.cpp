#include<iostream>

using namespace std;

/*
Find the nth number in Fibonacci series formed by adding last N numbers
e.g. if nth = 8, N = 5
series : 1,1,1,1,1,5,9,17
*/
int fibonacciWithLastNNumbers(int nth, int N){
	if(nth <= 0){
		return 0;
	}
	if(nth < N){
		return 1;	
	}
	int *arr = (int *)malloc(nth * sizeof(int));
	fill(arr,arr+5,1);
	arr[5] = 5;
	for(int i=6; i<nth; i++){
		arr[i] = arr[i-1] * 2 - arr[i-N];
	}
	return arr[nth-1];
}
/*
int main(){
	cout<<fibonacciWithLastNNumbers(8,5)<<endl;
	return 1;
}
*/