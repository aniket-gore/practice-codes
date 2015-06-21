#include<iostream>

void decimal_to_anybase(int n, int base) 
{ 
	int i, m, digits[1000], flag=0; 
	i=0; 
	printf("\n\n[%d] converted to base [%d] : ", n, base); 
	while(n) 
	{ 
		m=n%base; 
		digits[i]="0123456789abcdefghijklmnopqrstuvwxyz"[m]; 
		n=n/base; 
		i++; 
	} 
	//Eliminate any leading zeroes 
	for(i--;i>=0;i--) 
	{ 
		if(!flag && digits[i]!='0')
			flag=1; 
		if(flag)
			printf("%c",digits[i]); 
	} 
}