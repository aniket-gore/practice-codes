#include<iostream>

using namespace std;

/*
Two very large numbers are represented using arrays. Multiply these two numbers.
E.g. Two numbers 12 and 13 are represented as a=[1,2] and b=[1,3]. The expected result is 12*13=156 i.e. c=[1,5,6]
*/
void multiplyTwoNumbersRepresentedbyArray(int a[], int b[], int alen, int blen){
	int *c = (int *)malloc((alen+blen) * sizeof(int));
	fill(c,c+alen+blen,0);
	int c_index = alen + blen - 1;
	//2nd number
	for(int i=blen-1; i>=0; i--){
		int carry = 0;
		int shift = c_index;//c_index will denote the index where to start storing the result
		//1st number
		for(int j=alen-1; j>=0; j--){
			int mul = a[j] * b[i];
			int sum = mul + carry + c[shift];
			c[shift] = sum % 10;
			carry = sum / 10;
			shift--;
		}
		c[shift] += carry;//if there is a carry when adding the most significant digits
		c_index--;
	}

	for(int i=0; i<alen+blen; i++){
		cout<<" "<<c[i];
	}
}
