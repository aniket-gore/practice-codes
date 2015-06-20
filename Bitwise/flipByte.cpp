#include<iostream>

using namespace std;

/*
Flip byte / Reverse bits in a byte

Example: 
Input 
0101 0110 
1111 0011 

Output 
0110 1010 
1100 1111
*/

int flipByte(int byte){
	byte = (byte & 0x0F) << 4 | (byte & 0xF0) >> 4;
	byte = (byte & 0x33) << 2 | (byte & 0xCC) >> 2;
	byte = (byte & 0x55) << 1 | (byte & 0xAA) >> 1;
	return byte;
}