#include<iostream>

using namespace std;

/*
Initially there is a number n written on board. Two players start playing a game turn by turn.
Each player has to replace the number n written on the board by n-2^k (for some k >= 0 such that 2^k < n)? 
Also the number n-2^k has to be as beautiful as n (The beauty of a number depends on the number of one's in its 
binary representation). The player loses the game when he can't select any such k. 
Given the initial number n, determine which player will win the game if both players play optimally. n>0 and n <= 10^9.
*/

int beautifulNumberWinner(int num){
	int number_of_zeroes = 0, cumulative_count = 0;

	while(num){
		if(num & 0x01){
			cumulative_count += number_of_zeroes;
		}
		else{
			number_of_zeroes++;
		}
		num >>= 1;
	}
	return (cumulative_count % 2) ? 1 : 2;
}