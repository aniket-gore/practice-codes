/*
Referred:
Given n, output the numbers from 0 to 2^n-1 (inclusive) in n-bit binary form, in such an order that 
adjacent numbers in the list differ by exactly 1 bit.
*/
# include <stdio.h>
void grayCodes(char* number, int pos, int n, int reverse) {
	if(pos == n) {
		printf("%s\n", number);
		return;
	}
	if (!reverse) {
		number[pos] = '0';
		grayCodes(number, pos+1, n, reverse);
		number[pos] = '1';
		grayCodes(number, pos+1, n, !reverse);
	}
	else{ //roles of 0,1 are reversed, so anti image of above!
		number[pos] = '1';
		grayCodes(number, pos+1, n, !reverse);
		number[pos] = '0';
		grayCodes(number, pos+1, n, reverse);
	}
}
/*
void main() {
	int n=5, i;
	char number[32]={'\0'};
	for(i=0; i<n; i++)
		number[i] = '0';
	grayCodes(number, 0, n, 0);
}*/
