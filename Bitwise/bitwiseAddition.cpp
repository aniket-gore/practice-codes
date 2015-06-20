#include<iostream>

using namespace std;

//works for negative integers as well
//assume b as carry
int bitwiseAddition(int a, int b)
{	int sum=0,carry=0;
     if(b == 0)
         return a;
     sum = a ^ b;
     carry = (a & b) << 1;
     return bitwiseAddition(sum,carry);
}