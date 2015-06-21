#include<iostream>

void Binarytodecimal(int num) {
	long output=0;

	for(int i=0; num>0; i++) {
		if(num%10 == 1)
			output += pow(2.0,i);
		num = num/10;
	}
	printf("\nDecimal conversion = %d",output);
}