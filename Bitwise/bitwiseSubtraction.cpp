#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

int bitwiseSubtraction(int a, int b){
	return bitwiseAddition(a,bitwiseAddition(~b,1));
}