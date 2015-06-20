#include<iostream>

using namespace std;

//print all prime numbers less than equal to n
void sieveOfEratosthenes(int n){
	int *arr = new int[n+1];
	fill(arr,arr+n+1,0);

	if(n<2){
		return;
	}

	arr[0] = arr[1] = 1;
	for(int i=2; i<=n; i++){
		if(arr[i] == 0){
			cout<<i<<",";
			int count = 2;
			int index = i * count;
			while(index <= n){
				arr[index] = 1;
				index = i * ++count;
			}
		}
	}
}