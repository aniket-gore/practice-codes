#include<iostream>

using namespace std;

int allWaysOfCoinChange(int denominations[],int index, int amount, int **mem){
	if(index < 0 || amount < 0){
		return 0;
	}
	if(amount == 0){
		return 1;
	}
	if(mem[amount][index] != -1){
		return mem[amount][index];
	}
	mem[amount][index] = allWaysOfCoinChange(denominations,index-1,amount,mem) + allWaysOfCoinChange(denominations,index,amount - denominations[index],mem);
	return mem[amount][index];
}

//denominations need not be stored in a particular order
//return 1 if amount == 0.
int allWaysOfCoinChangeCaller(int denominations[],int length, int amount){
	int **mem = new int *[amount+1];//assign array of size 1 greater than amount
	for(int i=0; i<amount+1; i++){
		mem[i] = new int[length];
		fill(mem[i],mem[i]+length,-1);
	}
	return allWaysOfCoinChange(denominations,length-1,amount,mem);
}

//-------------------------------------------------------------------------------------------------------
// Recurrence : ACC(n,i) = ACC(n-arr[i],i) + ACC(n,i-1) and if n==0 then arr[n] = 1
// denominations should be in descending order
int allWaysOfCoinChangeBottomUp(int denominations[], int length, int amount){
	int **arr = (int **)malloc((amount+1) * sizeof(int *));
	for(int i=0; i<amount+1; i++){
		arr[i] = (int *)malloc(length * sizeof(int));
		fill(arr[i],arr[i]+length,0);
	}

	// fill the amount = 0 row to all 1s
	for(int i=0; i<length; i++){
		arr[0][i] = 1;
	}

	for(int i=1; i<amount+1; i++){
		for(int j=length-1; j>=0; j--){
			int use = 0, not_use = 0;
			if(i - denominations[j] >= 0){
				use = arr[i - denominations[j]][j];
			}
			if(j <= length-2){
				not_use = arr[i][j+1];
			}
			arr[i][j] = use + not_use;
		}
	}
	return arr[amount][0];
}