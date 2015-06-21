#include<iostream>

#define min(a,b) (a<b ? a : b)

using namespace std;

int minCoinChange(int denominations[],int index, int amount, int **mem){
	if(index < 0 || amount < 0){
		return 9999;
	}
	if(amount == 0){
		return 0;
	}
	if(mem[amount][index] != -1){
		return mem[amount][index];
	}

	int coin_not_used = minCoinChange(denominations,index-1,amount,mem);
	int coin_used = minCoinChange(denominations,index,amount - denominations[index],mem) + 1;
	mem[amount][index] = coin_not_used < coin_used ? coin_not_used : coin_used;
	return mem[amount][index];
}

//denominations need not be stored in a particular order
int minCoinChangeCaller(int denominations[],int length, int amount){
	int **mem = new int *[amount+1];//assign array of size 1 greater than amount
	for(int i=0; i<amount+1; i++){
		mem[i] = new int[length];
		fill(mem[i],mem[i]+length,-1);
	}
	return minCoinChange(denominations,length-1,amount,mem);
}

// Recurrence : MCC(n,i) = min(MCC(n-arr[i],i)+1, MCC(n,i-1))
// denominations should be in descending order
int minCoinChangeBottomUp(int denominations[], int length, int amount){
	int **arr = (int **)malloc((amount + 1) * sizeof(int *));
	for(int i=0; i<amount+1; i++){
		arr[i] = (int *)malloc(length * sizeof(int));
		fill(arr[i],arr[i]+length,0);
	}
	// amount = 0 row already filled with 0s

	for(int i=1; i<amount+1; i++){
		for(int j=length-1; j>=0; j--){
			int use = INT_MAX, not_use = INT_MAX;
			if(i - denominations[j] >= 0){
				use = arr[i - denominations[j]][j] + 1;
			}
			if(j <= length - 1){
				not_use = (j == length-1) ? i : arr[i][j+1];
			}
			arr[i][j] = min(use,not_use);
		}
	}
	return arr[amount][0];
}