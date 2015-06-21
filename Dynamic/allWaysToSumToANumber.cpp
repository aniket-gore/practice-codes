#include<iostream>

using namespace std;
/*
input : num = 4
output : 1,1,1,1
         2,1,1
		 2,2
		 3,1

other problem: if output needed is
1,1,1,1
1,1,2
1,2,1
2,1,1
2,2
1,3
3,1
Time : O((2^(n-1)) - 1)
*/

// arr = output array, index = index in output array
void allWaysToSumToANumber(int num, int index, int end_value, int *arr){
	if(num == 0){
		cout<<endl;
		// we are interested only till index-1
		for(int i=0; i<index; i++){
			cout<<arr[i]<<",";
		}
	}
	else if(num > 0){
		for(int value=1; value<=end_value; value++){
			arr[index] = value;
			allWaysToSumToANumber(num-value,index+1,value,arr);
		}
	}
}
/*
void allWaysToSumToANumberMemoized(int num, int index, int end_value, int *arr, int **mem){
	if(num == 0){
		cout<<endl;
		// we are interested only till index-1
		for(int i=0; i<index; i++){
			cout<<arr[i]<<",";
		}
	}
	else if(num > 0){
		if(mem[num][end_value] == -1){
			for(int value=1; value<=end_value; value++){
				arr[index] = value;
				allWaysToSumToANumberMemoized(num-value,index+1,value,arr,mem);
			}
		}
		
	}
}

void allWaysToSumToANumberCaller(int num){
	int **mem = new int*[num];
	for(int i=0; i<num; i++){
		mem[i] = new int[num];
		fill(mem[i],mem[i]+num,-1);
	}
	int *arr = new  int[num];
	allWaysToSumToANumberMemoized(num,0,num-1,arr,mem);
}
*/
/*
int main(){
	int *arr = new  int[7];
	int noofcalls = 0;
	allWaysToSumToANumber(4,0,3,arr);
	return 1;
}*/
