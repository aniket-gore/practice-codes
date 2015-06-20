#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

int bitwiseMultiplication(int a, int b){
	int output = 0;
	while(a){
		if(a & 1){
			output = bitwiseAddition(output,b);
		}
		a >>= 1;
		b <<= 1;
	}
	return output;
}