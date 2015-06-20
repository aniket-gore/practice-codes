#include<iostream>

using namespace std;

short reverseBitsInByte(short byte){
	byte = ((byte & 0xF0) >> 4) | ((byte & 0x0F) << 4);
	byte = ((byte & 0xCC) >> 2) | ((byte & 0x33) << 2);
	byte = ((byte & 0xAA) >> 1) | ((byte & 0x55) << 1);
	return byte;
}