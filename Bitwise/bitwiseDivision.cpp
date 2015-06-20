#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

int bitwiseDivision(int dividend, int divisor){
	int div = divisor;
	int quotient = 1;
	if(dividend < divisor){
		return 0;
	}
	if(dividend == divisor){
		return 1;
	}
	while(divisor <= dividend){
		divisor <<= 1;
		quotient <<= 1;
	}

	divisor >>= 1;
	quotient >>= 1;

	return bitwiseAddition(quotient,bitwiseDivision(bitwiseSubtraction(dividend,divisor),div));
}