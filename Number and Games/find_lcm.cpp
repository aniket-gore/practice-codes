#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

int find_lcm(int a, int b){
	return a*b / gcd(a,b);
}