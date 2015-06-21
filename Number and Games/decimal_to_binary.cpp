#include<iostream>

void Decimaltobinary(int num) {
	int remainder,count=0;
	int ch[20];
	int *p = ch;
	printf("\nBinary conversion = ");
	while(num){
		remainder = num%2;
		*(p+count) = remainder;
		count++;
		num = num/2;
	}

	count--;
	 do{
		printf("%d",*(p+count));
		count--;
	}while(count>=0);
}